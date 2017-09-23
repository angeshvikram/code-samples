#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> implementLogic(vector<int>& nums, int target,map<int,int>& mymap,int itr1) {
        vector<int> result;
        if(itr1 >= nums.size()){
            return result;
        }
        std::cout<<"\n target: " <<target;
        std::map<int,int>::iterator it = mymap.find(target-nums[itr1]);
        
        if (it != mymap.end()){
            std::cout<<"\n 2: " <<itr1<<" AND 1:"<<mymap[target-nums[itr1]];
            std::cout<<"\n 2Val: " <<nums[itr1]<<" AND 1Val:"<<nums[mymap[target-nums[itr1]]];
            result.push_back(mymap[target-nums[itr1]]);
            result.push_back(itr1);
            return result;
        }
        mymap[nums[itr1]] = itr1;
        

        // for (int itr2 = itr1; itr2 < nums.size();++itr2){
        //     if(((nums[itr2] + nums[itr1]) == target) && (itr1 != itr2)){
        //         result.push_back(itr1);
        //         result.push_back(itr2);
        //         return result;
        //     }
        // }
        
        return implementLogic(nums,target,mymap,++itr1);
}
vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mymap;
        return implementLogic(nums,target,mymap,0);
}
    

int main() {
	// your code goes here
	int myints[] = {3,2,4};
	
    std::vector<int> myvector (myints, myints+8);
    
    std::vector<int> resultVal = twoSum(myvector,6);
    for( int it = 0;it < resultVal.size();++it){
        std::cout << "\n -> "<<resultVal[it];
    }
	return 0;
}
