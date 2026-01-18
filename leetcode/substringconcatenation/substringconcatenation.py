class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:

        def makedict():
            d = dict()
            for i in words: 
                if i in d: 
                    d[i] += 1
                else:
                    d[i] = 1
            return d

        ans = []
        for start in range(len(words[0])):
            found = makedict()
            for i in range(start, len(s), len(words[0])):
                segment = s[i:i+len(words[0])]
                if segment in found:
                    found[segment] -= 1
                if len(set(found.values())) == 1 and 0 in found.values():
                    print(i)
                    ans.append(i-len(words)*len(words[0])+len(words[0]))
                if i >= start+len(words)*len(words[0])-len(words[0]) and s[i-len(words)*len(words[0])+len(words[0]):i-len(words)*len(words[0])+2*len(words[0])] in found:
                    found[s[i-len(words)*len(words[0])+len(words[0]):i-len(words)*len(words[0])+2*len(words[0])]] += 1 
        return list(set(ans))
