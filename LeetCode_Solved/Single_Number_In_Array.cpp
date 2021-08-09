//find non duplicate single number in an array
//Eg: inp = arr = [1,2,2,3,3,4,4]
//    out = 1
//Do it without using extra space

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int bits = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++){
            bits = bits^nums[i];
        }
        return bits;
    }
};