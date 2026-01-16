class Solution:
    def shortestPalindrome(self, s: str) -> str:
        def palindrome(string):
            if len(string)%2 == 0: 
                return string[:len(string)//2] == string[len(string)//2:][::-1]
            else:
                return string[:len(string)//2] == string[len(string)//2+1:][::-1]
        best = 0
        for i in range(1, len(s)+1):
            if palindrome(s[:i]):
                best = i
        return s[best:][::-1]+s
