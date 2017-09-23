
/*--------------------------------------------------------------------------------------+
|  ) Linked List                 |
|                      |
|  Date : 10:Nov:2006                |
|  Angesh Vikram                 |
+--------------------------------------------------------------------------------------*/
#include <iostream>
#define SUCCESS 0
#define ERROR 1
#define TRUE 1
#define FALSE 0

using namespace std;

template <class T>
class LinkList {
    T tData;
    LinkList* NextNode;

public:
    LinkList(T f_tData)
    {
        tData = f_tData;
        NextNode = NULL;
    }
    void vInsertNode(T f_iUserData, LinkList* f_CurrentNode);
    void vShowNode(LinkList* f_CurrentNode);
}; 

void LinkList::vShowNode(LinkList* f_CurrentNode){
    while (f_CurrentNode != NULL) {
        cout << f_CurrentNode->tData;
        f_CurrentNode = f_CurrentNode->NextNode;
    }
}
template <class T>
void LinkList::vInsertNode(T f_tUserData, LinkList* f_CurrentNode)
{
    if (f_CurrentNode->NextNode->tData > f_tUserData) {
        LinkList* Temp = new Link(f_tUserData);
        Temp->NextNode = f_CurrentNode->NextNode->NextNode;
        f_CurrentNode->NextNode = Temp;
    }
    else {
        if (f_CurrentNode->NextNode->NextNode == NULL) {
            f_CurrentNode->NextNode->NextNode = new Link(f_tUserData);
        }
        else
            vInsertNode(f_tUserData, f_CurrentNode->NextNode);
    }
}
int main()
{
    int iUserChoice = 0;
    LinkList* StartLink = Null;
    while (TRUE) {
        cout << endl
             << "Enter the Option for \n 1). Insert A Node \n 2). Delete A Node \n 3). Show The Linked List \n 4). Exit ";
        fflush(stdin);
        cin >> iUserChoice;
        switch (iUserChoice) {
        case 1:
            if (StartLink == NULL) {
                int iUserData = 0;
                cout << endl
                     << "Enter The Data Value ";
                cin >> iUserData;
                StartLink = new Link(iUserData);
            }
            else {
                int iUserData = 0;
                cout << endl
                     << "Enter The Data Value ";
                cin >> iUserData;
                if (StartLink->iData > iUserData)
                    ;
                {
                    LinkList* Temp = new Link(iUserData);
                    Temp->NextNode = StartLink;
                    StartLink = Temp;
                }
                else StartLink->vInsertNode(iUserData, StartLink);
            }
            break;
        case 2:
            break;
        case 3:
            StartLink->vShowNode(StartLink);
            break case 4 : break;
        }
        if (iUserChoice != 4) {
            fflush(stdin);
            cout << "\n ==================== ";
            cout << "\nEnter 0 if you want to check again \n";
            cin >> iMax;
            if (iMax == ERROR)
                break;
        }
        else
            break;
    }
    return SUCCESS;
}
