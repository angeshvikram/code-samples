

/*--------------------------------------------------------------------------------------+
|  ) Sorting Algo                |
|                      |
|  Date : 23:Nov:2006                |
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
#define ERROR -1
#define TRUE 1
#define FALSE 0
#define ON 1
#define OFF 0
/*--------------------------------------------------------------------------------------+
|  Global Data Information               |
+--------------------------------------------------------------------------------------*/

static int g_siMemmoryCheck = OFF; // ----------------Memmory check switch is on ------------------//
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
|  Function QuickSort                |
+--------------------------------------------------------------------------------------*/
int iQuickSort(int f_iSizeOfArray, int* f_iArrayP)
{
    int* LocalArray = new int(f_iSizeOfArray);
    int iLoop, jLoop, iTemp;
    for (iLoop = 0; iLoop < f_iSizeOfArray; iLoop++) {
        LocalArray[iLoop] = f_iArrayP[iLoop];
    }
    // TO write code for Quick Sort --------------------------------------------//
    cout << "\n\n Write the QUICK SORT code to Sort The following array : \n";
    for (iLoop = 0; iLoop < f_iSizeOfArray; iLoop++) {
        cout << " ";
        cout << LocalArray[iLoop];
    }

    delete (LocalArray);
    return SUCCESS;
}
/*--------------------------------------------------------------------------------------+
|  End QuickSort                 |
+--------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------+
|  Function MergeFunc                |
+--------------------------------------------------------------------------------------*/
void vMergeFunc(int f_MainArray[], int f_TempArray[], int f_Left, int f_Mid, int f_Right)
{
    int i, left_end, num_elements, tmp_pos;
    left_end = f_Mid - 1;
    tmp_pos = f_Left;
    num_elements = f_Right - f_Left + 1;
    while ((f_Left <= left_end) && (f_Mid <= f_Right)) {
        if (f_MainArray[f_Left] <= f_MainArray[f_Mid]) {
            f_TempArray[tmp_pos] = f_MainArray[f_Left];
            tmp_pos = tmp_pos + 1;
            f_Left = f_Left + 1;
        }
        else {
            f_TempArray[tmp_pos] = f_MainArray[f_Mid];
            tmp_pos = tmp_pos + 1;
            f_Mid = f_Mid + 1;
        }
    }
    while (f_Left <= left_end) {
        f_TempArray[tmp_pos] = f_MainArray[f_Left];
        f_Left = f_Left + 1;
        tmp_pos = tmp_pos + 1;
    }
    while (f_Mid <= f_Right) {
        f_TempArray[tmp_pos] = f_MainArray[f_Mid];
        f_Mid = f_Mid + 1;
        tmp_pos = tmp_pos + 1;
    }
    for (i = 0; i <= num_elements; i++) {
        f_MainArray[f_Right] = f_TempArray[f_Right];
        f_Right = f_Right - 1;
    }
}
/*--------------------------------------------------------------------------------------+
|  End MergeFunc                 |
+--------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------+
|  Function Merge_sort                |
+--------------------------------------------------------------------------------------*/
void vMerge_sort(int f_MainArray[], int f_TempArray[], int f_Left, int f_Right)
{
    int mid;
    if (f_Right > f_Left) {
        mid = (f_Right + f_Left) / 2;
        vMerge_sort(f_MainArray, f_TempArray, f_Left, mid);
        vMerge_sort(f_MainArray, f_TempArray, mid + 1, f_Right);
        vMergeFunc(f_MainArray, f_TempArray, f_Left, mid + 1, f_Right);
    }
}
/*--------------------------------------------------------------------------------------+
|  End Merge_sort                 |
+--------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------+
|  Function MergeSort                |
+--------------------------------------------------------------------------------------*/
int iMergeSort(int f_iSizeOfArray, int* f_iArrayP)
{
    int* LocalArray = new int(f_iSizeOfArray);
    int* TempArray = new int(f_iSizeOfArray);
    int iLoop, jLoop, iTemp;
    for (iLoop = 0; iLoop < f_iSizeOfArray; iLoop++) {
        LocalArray[iLoop] = f_iArrayP[iLoop];
    }
    vMerge_sort(LocalArray, TempArray, 0, f_iSizeOfArray - 1);
    cout << "\n\n Sorted array is : \n";
    for (iLoop = 0; iLoop < f_iSizeOfArray; iLoop++) {
        cout << " ";
        cout << LocalArray[iLoop];
    }

    delete (LocalArray);
    return SUCCESS;
}
/*--------------------------------------------------------------------------------------+
|  End MergeSort                 |
+--------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------+
|  Function BubbleSort                |
+--------------------------------------------------------------------------------------*/
int iBubbleSort(int f_iSizeOfArray, int* f_iArrayP)
{
    int* LocalArray = new int(f_iSizeOfArray);
    int iLoop, jLoop, iTemp;
    for (iLoop = 0; iLoop < f_iSizeOfArray; iLoop++) {
        LocalArray[iLoop] = f_iArrayP[iLoop];
    }
    for (iLoop = (f_iSizeOfArray - 1); iLoop >= 0; iLoop--) {
        for (jLoop = 1; jLoop <= iLoop; jLoop++) {
            if (LocalArray[jLoop - 1] > LocalArray[jLoop]) {
                iTemp = LocalArray[jLoop - 1];
                LocalArray[jLoop - 1] = LocalArray[jLoop];
                LocalArray[jLoop] = iTemp;
            }
        }
    }
    cout << "\n\n Sorted array is : \n";
    for (iLoop = 0; iLoop < f_iSizeOfArray; iLoop++) {
        cout << " ";
        cout << LocalArray[iLoop];
    }

    delete (LocalArray);
    return SUCCESS;
}
/*--------------------------------------------------------------------------------------+
|  End BubbleSort                 |
+--------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------+
|  Function InsertionSort               |
+--------------------------------------------------------------------------------------*/
int iInsertionSort(int f_iSizeOfArray, int* f_iArrayP)
{
    int* LocalArray = new int(f_iSizeOfArray);
    int iLoop, jLoop, iIndex;
    for (iLoop = 0; iLoop < f_iSizeOfArray; iLoop++) {
        LocalArray[iLoop] = f_iArrayP[iLoop];
    }
    for (iLoop = 1; iLoop < f_iSizeOfArray; iLoop++) {
        iIndex = LocalArray[iLoop];
        jLoop = iLoop;
        while ((jLoop > 0) && (LocalArray[jLoop - 1] > iIndex)) {
            LocalArray[jLoop] = LocalArray[jLoop - 1];
            jLoop = jLoop - 1;
        }
        LocalArray[jLoop] = iIndex;
    }
    cout << "\n\n Sorted array is : \n";
    for (iLoop = 0; iLoop < f_iSizeOfArray; iLoop++) {
        cout << " ";
        cout << LocalArray[iLoop];
    }

    delete (LocalArray);
    return SUCCESS;
}
/*--------------------------------------------------------------------------------------+
|  End InsertionSort                |
+--------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------+
|  Void Main()                  |
+--------------------------------------------------------------------------------------*/
int main()
{
    int iUserChoice = 0;
    int* iArrayP = NULL;
    int iSizeOfArray = 0;
gotoStartOfMain:
    cout << endl
         << "\nEnter the Number of elements of the array \n";
    cin >> iSizeOfArray;
    if (iArrayP != NULL)
        delete (iArrayP);

    iArrayP = new int(iSizeOfArray);
    cout << endl
         << "\nEnter the Value for the Array elements \n";
    for (int iLoop = 0; iLoop < iSizeOfArray; iLoop++) {
        int iValue = 0;
        cout << "\n Enter the value for " << (iLoop + 1) << " Element: \n";
        cin >> iValue;
        iArrayP[iLoop] = iValue;
    }
    while (TRUE) {
        cout << endl
             << "Enter the Option for \n 1). INSERTION SORT \n 2). BUBBLE SORT \n 3). MERGE SORT \n 4). QUICK SORT \n 5). IF WANT TO CHANGE THE ARRAY AND ITS ELEMENT VALUE \n 6). FOR Exit \n";
        fflush(stdin);
        cin >> iUserChoice;
        switch (iUserChoice) {
        case 1: {
            iInsertionSort(iSizeOfArray, iArrayP);
            break;
        }
        case 2: {
            iBubbleSort(iSizeOfArray, iArrayP);
            break;
        }
        case 3: {
            iMergeSort(iSizeOfArray, iArrayP);
            break;
        }
        case 4: {
            iQuickSort(iSizeOfArray, iArrayP);
            break;
        }
        case 5: {
            goto gotoStartOfMain;
            break;
        }
        case 6: {
            iUserChoice = ERROR;
            break;
        }
        }
        if (iUserChoice == ERROR)
            break;
    }
    delete (iArrayP);
    return SUCCESS;
}
/*--------------------------------------------------------------------------------------+
|  End Main()                  |
+--------------------------------------------------------------------------------------*/
