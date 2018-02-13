#include <iostream>
#include <vector>
using namespace std;


void testVector(vector<int> obj){
        cout<<obj.empty();
        if(!obj.empty()){
                cout<<"it is not empty"<<endl;
        }
        while (!obj.empty())
        {       
                cout<<obj.back()<<endl;
                obj.pop_back();
        }
}

bool binarySearch(int value,vector<int> obj,int _startPos, int _endPointer){
        if(obj.size() == 0){
                cout<<"size is zero";
                return false;
        }

        if(_startPos == _endPointer){
                if(value == obj.at(_startPos)){
                        return true;
                }
                else{
                        return false;
                }
        }
        int middlePointer = (_endPointer + _startPos)/2;
        if(value == obj.at(middlePointer)){
                return true;
        }
        else if(value > obj.at(middlePointer)){
                return binarySearch(value,obj,(middlePointer+1),_endPointer);
        }
        else {
                return binarySearch(value,obj,_startPos,(middlePointer-1));
        }
}

int main() {
        // your code goes here
        vector<int> testObj;

        testObj.push_back(1);

        for(int i;i<15;++i){
                testObj.push_back(i+i);
        }

        //testVector(testObj);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<testObj.size(); i++)
                std::cout <<testObj.at(i)<<endl;
        std::cout << '\n';

        int input;

        while(true){
                cin>>input;
                cout<<input<<endl;

                if(input == 0)
                        break;
                if(binarySearch(input,testObj,0,testObj.size()-1)){
                        cout<<"It is found"<<endl;
                }
                else{
                        cout<<"It is not found"<<endl;
                }
        }
        return 0;
}
