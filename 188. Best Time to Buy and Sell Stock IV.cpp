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
      int solveTabular(vector<int>&prices,int n,int k){
        
       vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(3,vector<int>(k+1,0)));

        for(int index = n-1;index>=0;index--){
           for(int j=0;j<2;j++){
               for(int limit=1;limit<=k;limit++){
                    int profit = 0;
                if(j){
                    int take = -prices[index] + dp[index+1][0][limit];
                    int skip  = 0+ dp[index+1][1][limit];
                    profit = max(take, skip);
                }else{
                    int take = prices[index] + dp[index+1][1][limit-1];
                    int skip  = 0+ dp[index+1][0][limit];
                    profit = max(take, skip);
                }
                dp[index][j][limit] = profit;
                }
               }
        }
        return dp[0][1][k];
    }
        int solveTabularSpaceConstant(vector<int>&prices,int n,int k){
        
       vector<vector<int>> cur(2, vector<int>(k+1,0));
        vector<vector<int>> next(2, vector<int>(k+1,0));

        for(int index = n-1;index>=0;index--){
           for(int j=0;j<2;j++){
               for(int limit = 1;limit<=k;limit++){
                int profit = 0;
                if(j){
                    int take = -prices[index] + next[0][limit];
                    int skip  = 0+ next[1][limit];
                    profit = max(take, skip);
                }else{
                    int take = prices[index] + next[1][limit-1];
                    int skip  = 0+ next[0][limit];
                    profit = max(take, skip);
                }
                cur[j][limit] = profit;
                }
           }
                next = cur;
        }
        return next[1][k];
    }
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();

        //solve topdown
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(3,vector<int>(k+1,-1)));
        return solve(0,1,prices,dp,k);
        //bottom up
        //return solveTabular(prices, n,k);
        //space optimized to O(k)
      // return solveTabularSpaceConstant(prices, n,k);
    }
};
