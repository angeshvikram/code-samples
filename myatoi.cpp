#include <iostream>
#include <string>

using namespace std;

bool isNotInteger(int i){
    if((47<i) && (i<58)){
        return false;
    }
    return true;
}

bool onlyOneDecimalOrSignCheck(string str){
    std::size_t found = str.find(".");
    std::size_t rfound = str.rfind(".");
    
    std::size_t plus = str.find("+");
    std::size_t rplus = str.rfind("+");
        
    std::size_t minus = str.find("-");
    std::size_t rminus = str.rfind("-");

    if(rfound == found){
        return true;
    }
    return false;
}

int convert(string str,int i,bool _decimalFound,int _sign,int _signCount,int _decimalCount,int _digitCount,bool _started){
    bool _signFound = false;
    if((str[0] == 0) || (str.empty())){
        cout<<"without sign:"<<i;
        cout<<"with sign:"<<i*_sign;
        return i*_sign;
    }
    if(_digitCount >= 10){
        cout<<"\n M : "<<i;
        cout<<"\n is : "<<isNotInteger(str[1]);
        cout<<"\n str1 : "<<str[0];
        if((_sign == 1)&&((i>=2147483647)||(!isNotInteger(str[0])))){
            cout<<"M1 "<<i;
            return 2147483647;
        }else if((_sign == -1)&&((i>=2147483648) || (!isNotInteger(str[0])))){
            cout<<"M2 "<<i;
            return -2147483648;
        }
    }
    
    if(isNotInteger(str[0])){
        if((_started) &&(str[0] == 32)){
            return i*_sign;
        }

        if(str[0] == 46){
            _decimalFound = true;
            ++_decimalCount;
            _started = true;
        }else if (str[0] == 45){
            _sign = -1;
            _signFound = true;
            ++_signCount;
            _started = true;
        }
        else if(str[0] == 43){
            _sign = 1;
            _signFound = true;
            ++_signCount;
            _started = true;
        }
        else if(str[0] == 32){
            _signFound = true;
        }
        else{
            cout<<"\n return i: "<<i;
            cout<<"\n return i_sign : "<<(i*_sign);
            return i*_sign;
        }
    }else{
        _started = true;
    }
    
    if((_signCount>1) || (_decimalCount > 1)){
        return i*_sign;
    }
    
    if((!_decimalFound) && (!_signFound)){
        i = i *  10 + (str[0] - 48) ;
        ++_digitCount;
    }
    
    if(!isNotInteger(str[1])){
        // Max  check
        if((i >= 214748364) && (((str[1] - 48)>7) && (_sign == 1))){
            cout<<"Max "<<i;
            return 2147483647;
        }

        // Min  check
        if((i >= 214748364) && (((str[1] - 48)>8) && (_sign == -1))){
            cout<<"Min "<<i;
            return -2147483648;
        }
    }

    return convert(str.substr(1),i,_decimalFound,_sign,_signCount,_decimalCount,_digitCount,_started);
}

    int myAtoi(string str) {
//        if(onlyOneDecimalCheck(str)){
    	    return convert(str,NULL,false,1,0,0,0,false);
//	    }
//        return NULL;
    }

int main() {
	// your code goes here
	//string str = "      -11919730356x";
	//string str = "2147483648";
	string str = " -1010023630o4";
	
	int a = myAtoi(str);
	cout<<"\n return : "<<a;
	return 0;
}
