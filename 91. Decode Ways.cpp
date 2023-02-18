class Solution {
public:
    int solve(string s, int n,vector<int>& memo){
       if(memo[n]>=0) return memo[n];
      int count = 0;
      if(s[n]>'0')  count+= solve(s, n+1,memo);
      if(n<s.size()-1 && (s[n]=='1' or s[n]=='2' and s[n+1]<='6')) {
       count+= solve(s,n+2,memo);
       }
        memo[n]=count;
        return count;
 }
    int numDecodings(string s) {
        vector<int>memo(s.size() + 1, -1);
        memo[s.size()] = 1;
        return solve(s, 0,memo);
    }
};
