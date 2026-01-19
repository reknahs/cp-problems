class Solution:
    def generateParenthesis(self, n: int) -> List[str]:

        ans = []
        
        def dp(outside, inside, curr): 
            if len(curr) == n*2:
                ans.append(curr)
            else: 
                if outside > 0:
                    dp(outside-1, inside, curr+")")
                if inside > 0: 
                    dp(outside+1, inside-1, curr+"(")
        dp(1, n-1, "(")

        return ans
