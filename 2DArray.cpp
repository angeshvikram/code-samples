#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	char arrObj[5][5] = {
	                    {'a','b','c','d','e'},
	                    {'a','b','c','d','e'},
	                    {'a','b','c','d','e'},
	                    {'a','b','c','d','e'},
	                    {'a','b','c','d','e'}};
	                    
    int rows =  sizeof arrObj / sizeof arrObj[0];
    int cols = sizeof arrObj[0] / sizeof(char);
	                    
	cout <<"sizeof arrObj "<< sizeof arrObj << endl;
	cout << "rows" << rows << endl;
	cout << "cols" << cols << endl;
	
	return 0;
}
