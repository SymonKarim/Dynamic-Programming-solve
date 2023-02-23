class Solution {
public:
    int solve(int index,int buy, vector<int>&prices, vector<vector<vector<int>>>&dp,int limit){
        if(index>=prices.size()) return 0;
        if(limit==0) return 0;
        if(dp[index][buy][limit]!=-1) return dp[index][buy][limit];
        int profit = 0;
        if(buy){
            int take = -prices[index] + solve(index+1, 0, prices, dp,limit);
            int skip  = 0+ solve(index+1, 1, prices,dp,limit);
            profit = max(take, skip);
        }else{
            int take = prices[index] + solve(index+1, 1, prices, dp,limit-1);
            int skip  = 0+ solve(index+1, 0, prices,dp,limit);
            profit = max(take, skip);
        }
        return dp[index][buy][limit]=profit;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        //solve topdown
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(3,vector<int>(3,-1)));
        return solve(0,1,prices,dp,2);

    }
};
