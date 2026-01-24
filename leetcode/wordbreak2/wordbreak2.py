class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        starts = [[] for i in range(len(s))]
        for i in range(len(s)):
            for word in wordDict:
                if i+len(word) > len(s):
                    continue
                if s[i:i+len(word)] == word:
                    starts[i].append(word)

        dp = [[] for i in range(len(s)+1)]
        for i in starts[0]: 
            dp[len(i)].append(i)
        for i in range(len(dp)-1):
            if len(dp[i]) == 0:
                continue 
            for j in starts[i]: 
                for prefix in dp[i]:
                    dp[i+len(j)].append(prefix+" "+j)
        return dp[-1]
