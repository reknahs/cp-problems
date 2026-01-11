def number(r, c):
    start = (max(r, c)-1)**2+1
    end = max(r, c)**2
    if max(r, c)%2 == 0:
        if r < c:
            print(start+r-1)
        else:
            print(end-c+1)
    else:
        if c < r:
            print(start+c-1)
        else:
            print(end-r+1)

t = int(input())
for i in range(t):
    indices = input().split()
    number(int(indices[0]), int(indices[1]))
