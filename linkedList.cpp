
/*--------------------------------------------------------------------------------------+
|  ) Linked List                 |
|                      |
|  Date : 10:Nov:2006                |
|  Angesh Vikram                 |
+--------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------+
|  Header File                  |
+--------------------------------------------------------------------------------------*/
#include <iostream>
#include <stdio.h>
//#include <process.h> //-------- Only in WIN XX OS -----------------------------------//
#include <memory>
#include <string>

using namespace std;

/*--------------------------------------------------------------------------------------+
|  # define Macros                 |
+--------------------------------------------------------------------------------------*/
#define SUCCESS 0
#define ERROR 1
#define TRUE 1
#define FALSE 0
#define ON 1
#define OFF 0
/*--------------------------------------------------------------------------------------+
|  Global Data Information               |
+--------------------------------------------------------------------------------------*/

static int g_siMemmoryCheck = ON; // ----------------Memmory check switch is on ------------------//
FILE* g_fFileP = NULL; // ----------------File Pointer To the Program -----------------//

/*--------------------------------------------------------------------------------------+
|  Overloaded New Operatoe               |
+--------------------------------------------------------------------------------------*/
void* operator new(size_t f_size)
{
    void* ptr;
    if (g_siMemmoryCheck == ON) // ----------------Check Memmory Leak switch -------------------//
    {
        if (g_fFileP == NULL) // ----------------First Time Call to new operator -------------//
        {
            if ((g_fFileP = fopen("MemmoryLeeak.raw", "w")) == NULL) //--------openning File in write mode -//
            {
                cout << endl
                     << "Error openning MemmoryLeeak.raw in write mode ";
                exit(1);
            }
        }
    }
    if ((ptr = malloc(f_size)) == NULL) {
        cout << endl
             << "out of memmory";
        exit(1);
    }
    if (g_siMemmoryCheck == ON) // ----------------Check Memmory Leak switch -------------------//
    {
        fprintf(g_fFileP, " :> New (%d) => %x \n ", f_size, ptr);
    }
    return ptr;
}
/*--------------------------------------------------------------------------------------+
|  Overloaded delete Operatoe              |
+--------------------------------------------------------------------------------------*/
void operator delete(void* f_ptr)
{
    if (g_siMemmoryCheck == ON) // ----------------Check Memmory Leak switch -------------------//
    {
        if (g_fFileP == NULL) // ----------------First Time Call to new operator -------------//
        {
            if ((g_fFileP = fopen("MemmoryLeeak.raw", "w")) == NULL) //--------openning File in write mode -//
            {
                cout << endl
                     << "Error openning MemmoryLeeak.raw in write mode ";
                exit(1);
            }
        }
    }
    if (f_ptr) // ----------------- Checking for valid pointer ----------------//
    {
        free((char*)f_ptr);
    }
    if (g_siMemmoryCheck == ON) // ----------------Check Memmory Leak switch -------------------//
    {
        fprintf(g_fFileP, " :> Free <= %x \n ", f_ptr);
    }
}
/*--------------------------------------------------------------------------------------+
|  Class LinkList                |
+--------------------------------------------------------------------------------------*/
template <class T>
class LinkList {
private:
    T tData;
    LinkList* NextNode;

public:
    LinkList(T f_tData)
    {
        tData = f_tData;
    }
    int iCheckData(T f_tData)
    {
        if (tData > f_tData)
            return SUCCESS;
        else
            return ERROR;
    }
    LinkList* llInsertNode(T f_tUserData, LinkList* f_CurrentNode);
    void vShowNode(LinkList* f_CurrentNode);
    void vReverseLink(LinkList** f_CurrentNode);
};
/*--------------------------------------------------------------------------------------+
|  Function Insert Node               |
+--------------------------------------------------------------------------------------*/
template <class T>
LinkList<T>* LinkList<T>::llInsertNode(T f_tUserData, LinkList* f_CurrentNode)
{
    if (f_CurrentNode == NULL) {
        f_CurrentNode = new LinkList(f_tUserData);
        return f_CurrentNode;
    }
    else {
        if (f_CurrentNode->iCheckData(f_tUserData) == SUCCESS) {
            LinkList* Temp = new LinkList(f_tUserData);
            Temp->NextNode = f_CurrentNode;
            return Temp;
        }
        else {
            f_CurrentNode->NextNode = llInsertNode(f_tUserData, f_CurrentNode->NextNode);
            return f_CurrentNode;
        }
    }
}
/*--------------------------------------------------------------------------------------+
|  Function Show Node                |
+--------------------------------------------------------------------------------------*/
template <class T>
void LinkList<T>::vShowNode(LinkList* f_CurrentNode)
{
    while (f_CurrentNode != NULL) {
        cout << endl
             << f_CurrentNode->tData;
        f_CurrentNode = f_CurrentNode->NextNode;
    }
}
/*--------------------------------------------------------------------------------------+
|  Function Show Node                |
+--------------------------------------------------------------------------------------*/
template <class T>
void LinkList<T>::vReverseLink(LinkList** f_HeadNode)
{
    LinkList* TempHead = *f_HeadNode;
    if ((TempHead != NULL) && (TempHead->NextNode != NULL)) {
        TempHead = TempHead->NextNode;
        if (TempHead->NextNode == NULL) //-------- Only For Two Nodes ;
        {
            TempHead->NextNode = *f_HeadNode;
            *f_HeadNode = TempHead;
            TempHead->NextNode->NextNode = NULL; //------- Making the First Node NULL ;
        }
        else {
            LinkList* Temp = *f_HeadNode;
            Temp->NextNode = NULL; //------- Making the First Node NULL ;
            *f_HeadNode = Temp;
            //   while(TempHead->NextNode != NULL )
            while (TempHead != NULL) {
                Temp = TempHead->NextNode;
                TempHead->NextNode = *f_HeadNode;
                *f_HeadNode = TempHead;
                TempHead = Temp;
            }
        }
    }
}
/*--------------------------------------------------------------------------------------+
|  Void Main()                  |
+--------------------------------------------------------------------------------------*/
int main()
{
    int iUserChoice = 0;
    LinkList<int>* StartLink = NULL;
    while (TRUE) {
        cout << endl
             << "Enter the Option for \n 1). Insert A Node \n 2). Reverse the Link List A Node \n 3). Show The Linked List \n 4). Exit \n";
        fflush(stdin);
        cin >> iUserChoice;
        switch (iUserChoice) {
        case 1: {
            int iUserData = 0;
            cout << endl
                 << "Enter The Data Value \n";
            cin >> iUserData;
            StartLink = StartLink->llInsertNode(iUserData, StartLink);
            break;
        }
        case 2: {
            cout << endl
                 << "Your Current Link List is : \n";
            StartLink->vShowNode(StartLink);
            StartLink->vReverseLink(&StartLink);
            cout << endl
                 << "Your Reversed Link List is : \n";
            StartLink->vShowNode(StartLink);
            break;
        }
        case 3: {
            StartLink->vShowNode(StartLink);
            break;
        }
        case 4: {
            break;
        }
        }
        if (iUserChoice != 4) {
            fflush(stdin);
            cout << "\n ==================== ";
            cout << "\nEnter 0 if you want to check again \n";
            cin >> iUserChoice;
            if (iUserChoice == ERROR)
                break;
        }
        else
            break;
    }
    delete (StartLink);
    return SUCCESS;
}
