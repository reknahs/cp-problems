class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        prefix = [1]
        for i in range(1, len(s)):
            if s[i] == s[i-1]: 
                prefix.append(prefix[i-1]+1)
            else: 
                prefix.append(1)
        memo = []
        def evaluate(a, b, prev):
            if (a, b, prev) in memo:
                return False
            else:
                memo.append((a, b, prev))
            if len(b) == 0 and len(a) == 0: 
                return True
            elif len(b) == 0:
                return False
            elif b[0] not in ["*", "."] and (len(a) == 0 or b[0] != a[0]): 
                if len(b) > 1 and b[1] == "*": 
                    if evaluate(a, b[1:], b[0]):
                        return True
                else:
                    return False
            elif len(a) == 0 and b[0] != "*" and not (len(b) > 1 and b[1] == "*"):
                return False
            elif (b[0] not in ["*", "."] and b[0] == a[0]) or b[0] == ".": 
                if len(b) > 1 and b[1] == "*": 
                    if evaluate(a, b[1:], b[0]):
                        return True
                if evaluate(a[1:], b[1:], b[0]):
                    return True
            elif b[0] == "*":
                i = 0
                if evaluate(a[i:], b[1:], b[0]):
                    return True
                while i < len(a) and (a[i] == prev or prev == "."):
                    if evaluate(a[i+1:], b[1:], b[0]): 
                        return True
                    i += 1
            return False
        return evaluate(s, p, None)
