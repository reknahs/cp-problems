class Solution:
    def partition(self, s: str) -> List[List[str]]:

        def is_palindrome(a): 
            return a == a[::-1]

        ends = []
        for i in range(len(s)):
            ends.append([])
            for j in range(i+1, len(s)+1):
                if is_palindrome(s[i:j]): 
                    ends[-1].append(j)
        
        dp = [[] for i in range(len(ends)+1)]
        for end in ends[0]: 
            dp[end].append([s[:end]])
        for i in range(1, len(ends)): 
            for end in ends[i]:
                for j in dp[i]:
                    dp[end].append(j+[s[i:end]]) 
        return dp[-1]
