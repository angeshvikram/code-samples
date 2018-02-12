#include <iostream>
using namespace std;

void arrayLength(int _a[],int element ){

    for(int i = 0; i < element; ++i)
    {
        std::cout << _a[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
        // your code goes here

        int arrayObj[] = {1,3,5,8,9,13,16,19,21,24,25,27,29};
        int length = sizeof(arrayObj)/sizeof(arrayObj[0]);

        arrayLength(arrayObj,length);
        return 0;
}
