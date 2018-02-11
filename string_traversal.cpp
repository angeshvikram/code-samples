#include <iostream>
using namespace std;

void printChar(string _str){
    if(_str.size() > 0){
        cout << _str.substr(0,1);
        printChar(_str.substr(1,_str.size()-1));
    }
}

int main() {
	// your code goes here
	string str = "Hello";
	std::cout << str << std::endl;
	std::cout << str.size() << std::endl;
	
	string::iterator it;
    for (it = str.begin(); it < str.end(); it++) 
        cout << *it;
    cout << endl;
    printChar(str);
        
    cout << endl;
	
	return 0;
}
