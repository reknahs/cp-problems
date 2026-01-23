class Solution:
    def minCut(self, s: str) -> int:

        def is_palindrome(a): 
            return a == a[::-1]

        ends = []
        for i in range(len(s)):
            ends.append([])
            for j in range(i+1, len(s)+1):
                if is_palindrome(s[i:j]): 
                    ends[-1].append(j)
  
        dp = [10000000 for i in range(len(ends)+1)]
        for end in ends[0]: 
            dp[end] = 1
        for i in range(1, len(ends)): 
            for end ian ends[i]:
                dp[end] = min(dp[end], dp[i]+1)

        return dp[-1]-1
