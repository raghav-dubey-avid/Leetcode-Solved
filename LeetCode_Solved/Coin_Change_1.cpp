class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount == 0 || coins.size() == 0)
                return 0;
        
        int n = coins.size();
        
        vector<int> dp(amount+1, 1e6);
        //memset(dp,INT_MAX,sizeof(dp));
        
        dp[0] = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = coins[i]; j <= amount; j++){
                
                dp[j] = min(dp[j], 1 + dp[j-coins[i]]);
            }
        }
        return dp[amount] != 1e6 ? dp[amount] : -1;
    }    
};