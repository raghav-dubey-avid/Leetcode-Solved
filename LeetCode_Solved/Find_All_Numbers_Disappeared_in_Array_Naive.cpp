//Naive Solution using set
//Time - O(n)
//Space - O(n)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> ans;
        unordered_set<int> s;
        
        for(int i : nums){
            s.insert(i);
        }
        
        for(int i = 1; i <= nums.size(); i++){
            if(s.find(i) == s.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};