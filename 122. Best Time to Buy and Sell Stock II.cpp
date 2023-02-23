class Solution {
public:
    int solve(int index,int buy, vector<int>&prices, vector<vector<int>>&dp){
        if(index>=prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        int profit = 0;
        if(buy){
            int take = -prices[index] + solve(index+1, 0, prices, dp);
            int skip  = 0+ solve(index+1, 1, prices,dp);
            profit = max(take, skip);
        }else{
            int take = prices[index] + solve(index+1, 1, prices, dp);
            int skip  = 0+ solve(index+1, 0, prices,dp);
            profit = max(take, skip);
        }
        return dp[index][buy]=profit;

    }
    int solveTabular(vector<int>&prices,int n){
        
        vector<vector<int>>dp(n+1, vector<int>(2,0));

        for(int index = n-1;index>=0;index--){
           for(int j=0;j<2;j++){
                int profit = 0;
                if(j){
                    int take = -prices[index] + dp[index+1][0];
                    int skip  = 0+ dp[index+1][1];
                    profit = max(take, skip);
                }else{
                    int take = prices[index] + dp[index+1][1];
                    int skip  = 0+ dp[index+1][0];
                    profit = max(take, skip);
                }
                dp[index][j] = profit;
                }
        }
        return dp[0][1];
    }
        int solveTabularSpaceConstant(vector<int>&prices,int n){
        
        vector<int>cur(2,0);
        vector<int>next(2,0);

        for(int index = n-1;index>=0;index--){
           for(int j=0;j<2;j++){
                int profit = 0;
                if(j){
                    int take = -prices[index] + next[0];
                    int skip  = 0+ next[1];
                    profit = max(take, skip);
                }else{
                    int take = prices[index] + next[1];
                    int skip  = 0+ next[0];
                    profit = max(take, skip);
                }
                cur[j] = profit;
                }
                next = cur;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        //solve topdown
        // vector<vector<int>>dp(n+1, vector<int>(2,-1));
        // return solve(0,1,prices,dp);

        //solve bottom up
        //return solveTabular(prices,n);

         //solve in constant space,, took only 4 variable
        return solveTabularSpaceConstant(prices,n);
    }
};
