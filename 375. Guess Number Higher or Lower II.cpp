class Solution {
public:
    int solve(vector<int>& prices, int fee, bool buy, int index,vector<vector<int>>&dp){
           if(index==prices.size()) return 0;
           if(dp[index][buy] != -1) return dp[index][buy];
           int profit = 0,mx=0;
           if(buy){
               profit = max(-prices[index] + solve(prices, fee, 0, index+1, dp),solve(prices, fee, 1, index+1, dp));
           }else{
              profit = max(prices[index] - fee + solve(prices, fee, 1, index+1, dp),solve(prices, fee, 0, index+1, dp));
           }
           return dp[index][buy] = profit;
    }
    int solveTabular(vector<int>& prices, int fee){
       vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));

       for(int i = prices.size()-1;i>=0;i--){
           int profit = 0;
           for(int buy = 0; buy<2;buy++){
           if(buy){
               profit = max(-prices[i] + dp[i+1][0],dp[i+1][1]);
           }else{
              profit = max(prices[i] - fee +  dp[i+1][1], dp[i+1][0]);
           }
            dp[i][buy] = profit;
           }
       }
       return dp[0][1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        // vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        // return solve(prices,fee,  1, 0, dp);
        return solveTabular(prices, fee);
    }
};
