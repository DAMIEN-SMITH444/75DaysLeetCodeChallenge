class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> t(n, vector<bool>(n));

        for (int i = 0; i < n; i++) {
            t[i][i] = true;
        }
        int maxL = 1;
        int idx = 0;
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i < n - l + 1; i++) {
                int j = i + l - 1;
                if (s[i] == s[j] && l == 2) {
                    t[i][j] = true;
                    maxL = 2;
                    idx = i;
                } else if (s[i] == s[j] && t[i + 1][j - 1] == true) {
                    t[i][j] = true;
                    if (maxL < j - i + 1) {
                        maxL = j - i + 1;
                        idx = i;
                    }
                }

                else
                    t[i][j] = false;
            }
        }
        return s.substr(idx, maxL);
    }
};

/*
recursion + memoization

class Solution {
public:
    int dp[1001][1001];
    bool solve(string &s , int i , int j){
        if(i >= j )return true;

        if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == s[j]){
            return dp[i][j] = solve(s,i+1,j-1);
        }
        return false;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        int maxlen = INT_MIN;
        int sp = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(solve(s,i,j)){
                    if(maxlen < j - i + 1){
                        maxlen = j - i + 1;
                        sp = i ;
                    }
                }
            }
        }
        return s.substr(sp,maxlen);
    }
};

*/