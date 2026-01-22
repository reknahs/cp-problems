class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:

        def reduce(m, curlength): 
            newm = []
            hasone = False
            for i in range(1, len(m)):
                newm.append([])
                for j in range(1, len(m[i])):
                    newm[-1].append(int(m[i][j] == m[i-1][j] == m[i][j-1] == m[i-1][j-1] == 1))
                    if newm[-1][-1]: 
                        hasone = True  
            if hasone: 
                return reduce(newm, curlength+1)
            else: 
                return curlength-1
        
        if all(j == "0" for i in matrix for j in i): 
            return 0
        return reduce([[int(j) for j in i] for i in matrix], 2)**2
    
