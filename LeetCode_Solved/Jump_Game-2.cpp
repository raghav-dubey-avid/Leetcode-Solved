/*

Problem Statement : Given an array of non-negative integers nums, you are initially                     positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.


Problem Link: https://leetcode.com/problems/jump-game-ii/

*/


// Method-1 ( Recursive )

class Solution {
public:
 
   long long int jump(vector<int> nums , int curr, int dest)
    {       
            if(curr>=dest) return 0; 
            long long int tmp=INT_MAX;
			
            //Try Every jump 1 to nums[curr] jump
            //and find minimum steps need to reach to end
			
            for(int i=1;i<=nums[curr];i++)
            {
                tmp=min(tmp,1+jump(nums,curr+i,dest));  
            } 
         return tmp;  
    }
    
    int jump(vector<int>& nums) { 
         return jump(nums,0,nums.size()-1);
    }
};

/*Time Complexity: O(k^n), Where, k is max element of nums and n is size of nums.
Space Complexity: O(1). */


//Method-2 Single Pass


class Solution {
public:
    int jump( vector<int>& nums ) {
	    
	if( nums.size() < 2 ) return 0;   //base case
        
        int n = size(nums), i = 0, maxReachable = 0, lastJumpedPos = 0, jumps = 0;
	    while( lastJumpedPos < n - 1 ) {  
            maxReachable = max( maxReachable, i + nums[i] );   
            if( i == lastJumpedPos ) {			
                lastJumpedPos = maxReachable;     
                jumps++;                        
            }            
		    i++;
	    }
	    return jumps;
    }
};


//Time Complexity- O(n)
