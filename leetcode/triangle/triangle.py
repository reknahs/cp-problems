class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp = [triangle[0]]
        for i in range(1, len(triangle)):
            dp.append([-100000 for num in range(i+1)])
            dp[i][0] = dp[i-1][0]+triangle[i][0]
            for j in range(1, len(dp[i])-1): 
                dp[i][j] = triangle[i][j]+min(dp[i-1][j], dp[i-1][j-1])
            dp[i][len(dp[i])-1] = dp[i-1][len(dp[i])-2]+triangle[i][len(dp[i])-1]
        return min(dp[-1])
