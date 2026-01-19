

class Solution:
    def longestValidParentheses(self, s: str) -> int:

        dp = [0 for i in range(len(s)+1)]
        for i in range(1, len(s)): 
            if s[i] == ")" and s[i-1] == "(":
                # direct case: ()
                dp[i+1] = dp[i-1]+2
            elif s[i] == ")" and dp[i] > 0: 
                # indirect case: (())
                if i-dp[i]-1 >= 0 and s[i-dp[i]-1] == "(":
                    dp[i+1] = dp[i]+2+dp[i-dp[i]-1]

        return max(dp)
