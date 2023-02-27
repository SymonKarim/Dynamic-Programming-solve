class Solution {
public:
int sz = 0,tz =0;
    int solve(string &s, string &t, int i, int j, vector<vector<int>>&dp){
        if(i== sz) return 0;
        if(j==tz) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int x=0;
        if(s[i]==t[j]){
            x = 1+ solve(s,t, i+1, j+1,dp);
        }
        else x = max(solve(s,t,i+1,j,dp), solve(s,t,i,j+1,dp));
        
        return dp[i][j] = x;
    }
    int solveTabular(string &s, string &t){
    vector<vector<int>>dp(sz+1,vector<int>(tz+1,0));
        for(int i=sz-1;i>=0;i--){
            for(int j=tz-1;j>=0;j--){
                 int x = 0;
                 if(s[i]==t[j])
                      x = 1+ dp[i+1][j+1];
                 else x = max(dp[i+1][j], dp[i][j+1]);
                 dp[i][j] = x;
            }
        }return dp[0][0];
    }
    int solveTabularSpaceOptimized(string &s, string &t, int sz, int tz){
       vector<int>next(s.size()+1,0),curr(s.size()+1,0);
        for(int i=sz-1;i>=0;i--){
            for(int j=tz-1;j>=0;j--){
                 int x = 0;
                 if(s[i]==t[j])
                      x = 1+ next[j+1];
                 else x = max(next[j], curr[j+1]);
                 curr[j] = x;
            }
            next = curr;
        }return next[0];
    }
    int longestPalindromeSubseq(string s) {
         string t = s;
         reverse(t.begin(), t.end());
         return solveTabularSpaceOptimized(s,t,s.length(), t.length());
    }
};
