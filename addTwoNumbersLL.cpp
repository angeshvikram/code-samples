#include<iostream>

using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return implementationLogic(l1,l2,l1,0);
    }
private:
    ListNode* implementationLogic(ListNode* l1, ListNode* l2,ListNode* start,int _carry) {
        if((l1 == NULL)&&(l2==NULL)){
            return NULL;
        }

        if(l1 == NULL){
            l1 = new ListNode(0);
        }
        if(l2 == NULL){
            l2 = new ListNode(0);
        }
        
        if((l1->val + l2->val + _carry) >= 10){
            l1->val = ((l1->val + l2->val + _carry) % 10);
            _carry = 1;
        } else{
            l1->val = ((l1->val + l2->val + _carry) % 10);
            _carry = 0;
        }
        
        if((l1->next == NULL) && (l2->next == NULL)){
            if(_carry == 1){
                l1->next = new ListNode(1);
            }
            return start;
        }
        if(l1->next == NULL){
            l1->next = new ListNode(0);
        }
        if(l2->next == NULL){
            l2->next = new ListNode(0);
        }

        return implementationLogic(l1->next,l2->next,start,_carry); 
    }    
};

int main()
{
	Solution sol;
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	
	ListNode *result = sol.addTwoNumbers(l1,l2);
	
	std::cout<<"\n l1-val : ";
	while(result !=NULL){
	    std::cout<<result->val;
	    result = result->next;
	}

	return 0;
}
