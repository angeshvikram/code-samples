/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		//int[] myIntArray = {4,2,1};
		//int[] myIntArray = {1,1,1};
		//int[] myIntArray = {4,2,3};
		//int[] myIntArray = {3,3,2,2};
		//int[] myIntArray = {3,4,2,3};
		//int[] myIntArray = {2,3,3,2,4};
		int[] myIntArray = {1,2,4,5,3};
		
		Codechef Obj = new Codechef();
		Obj.checkPossibility(myIntArray);
	}
	
	public boolean checkPossibility(int[] nums) {
	    System.out.println(Arrays.toString(nums));
	    Codechef Obj = new Codechef();
	    boolean ret = Obj.checkPossibility1(nums);
	    System.out.println(ret);
	    return ret;
    }
    
    private boolean checkPossibility1(int[] nums) {
        int faultCount = 0;
        for(int i=0;i<nums.length;++i){
            if((nums.length>1) && (i < (nums.length-1))){
                if(nums[i] > nums[i+1]){
                    if(i == 0){
                        nums[i] = 1;
                    }
                    else{
                        if(nums[i-1]>nums[i+1]){
                            if((nums[i-1] != nums[i]) && (faultCount>0)){
                                return false;
                            }
                            nums[i+1] = nums[i];
                        }
                        else{
                            nums[i] = nums[i+1];
                        }
                    }
                    
                    ++faultCount;
                    if(faultCount>1){
                        return false;
                    }
                }
            }
        }
	    return true;
    }
}
