class Solution:
    def isMatch(self, s: str, p: str) -> bool:

        dp = [[False for j in range(len(p)+1)] for i in range(len(s)+1)]
        dp[0][0] = True 
        for i in range(1, len(dp[0])):
            # empty string and non empty pattern only match if pattern only consists of "*"
            dp[0][i] = dp[0][i-1] and p[i-1] == "*"
        
        # dp[i][j] is True if first i chars of s can match first i chars of p
        for i in range(1, len(dp)):
            for j in range(1, len(dp[i])):
                if p[j-1] == "*":
                    dp[i][j] = dp[i][j-1] or dp[i-1][j]
                elif dp[i-1][j-1]:
                    if s[i-1] == p[j-1] or p[j-1] == "?":
                        dp[i][j] = True
                    elif s[i-1] != p[j-1]: 
                        dp[i][j] = False
                else: 
                    dp[i][j] = False
        return dp[-1][-1]
