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
    int longestCommonSubsequence(string text1, string text2) {
         sz = text1.length(), tz = text2.length();
        vector<vector<int>>dp(sz,vector<int>(tz,-1));
        return solve(text1,text2,0,0,dp);
    }
};
