t = int(input())
for i in range(t):
    a, b = map(int, input().split())
    a, b = min(a, b), max(a, b)
    if b-a > a:
        print("NO")
        continue
    a, b = a - (b-a), b - 2*(b-a)
    a, b = a%3, b%3
    if a == 0 and b == 0:
        print("YES")
    else:
        print("NO")

