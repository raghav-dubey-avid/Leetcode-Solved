class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        //sort(nums.begin(), nums.end());
        
        
        int  low = 1, high = nums[nums.size()-1];
        int answer = 0;
        while(low <= high){
            long long int sum = 0;
            int mid = low + (high-low)/2;
            
            for(int i = 0; i < nums.size(); i++){
                
                if(nums[i]%mid == 0){
                    sum += (nums[i]/mid);
                }
                else{
                    sum += (nums[i]/mid)+1;
                }
            }
            
            if(sum > threshold){
                low = mid+1;
            }
            else{
                answer = mid;
                high = mid-1;
            }
        }
        return answer;
    }    
};