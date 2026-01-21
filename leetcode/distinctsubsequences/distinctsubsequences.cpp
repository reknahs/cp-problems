class Solution {

unsigned __int128 dp[1001][1001];

public:
    int numDistinct(string s, string t) {
        for(int i = 0; i < s.size(); i++) {
            dp[0][i] = 1;
        }
        dp[1][0] = t[0] == s[0];
        for(int i = 0; i < t.size(); i++) {
            for(int j = 1; j < s.size(); j++) {
                if(s[j] == t[i]) {
                    dp[i+1][j] += dp[i][j-1];
                }
                dp[i+1][j] += dp[i+1][j-1];
            }
        }
        return dp[t.size()][s.size()-1];
    }
};
