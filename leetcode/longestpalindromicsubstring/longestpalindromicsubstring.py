class Solution:
    def longestPalindrome(self, s: str) -> str:

        def best_palindrome(center):
            # odd palindrome case
            left = center
            right = center
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1

            # even palindrome case 
            left2 = None
            right2 = None
            if center < len(s)-1 and s[center] == s[center+1]:
                left2 = center-1
                right2 = center+2
                while left2 >= 0 and right2 < len(s) and s[left2] == s[right2]:
                    left2 -= 1
                    right2 += 1
            if left2 is not None: 
                if right2-left2 > right-left: 
                    return s[left2+1:right2]
            return s[left+1:right]

        best = ""
        for center in range(len(s)):
            constructed = best_palindrome(center)
            if len(constructed) > len(best):
                best = constructed
        return best
