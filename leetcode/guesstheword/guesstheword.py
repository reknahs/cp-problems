# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
# class Master:
#     def guess(self, word: str) -> int:

class Solution:
    def findSecretWord(self, words: List[str], master: 'Master') -> None:
        similar = []
        most_common = []
        for i in range(len(words)):
            similar.append([])
            most_common.append(0)
            for j in range(len(words)):
                similar[i].append(0)
                for ind in range(6):
                    similar[i][j] += int(words[i][ind] == words[j][ind])
                most_common[i] = max(most_common[i], similar[i].count(similar[i][j]))
        exclude = []

        def narrow(ind, num):
            for i in range(len(words)):
                if i not in exclude and similar[ind][i] != num: 
                    exclude.append(i)
        
        def get_best_index():
            best = 0, 10000000
            for i in range(len(most_common)):
                if i not in exclude and most_common[i] < best[1]: 
                    best = i, most_common[i]
            return best[0]

        start = get_best_index()

        while start != 10000000:
            if start not in exclude:
                num = master.guess(words[start])
                if num == 6: 
                    break
                narrow(start, num)
            start = get_best_index()
        
