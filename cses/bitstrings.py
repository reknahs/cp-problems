n = int(input())
ans = 2
for i in range(n-1):
    ans = ans * 2 % (1e9+7)
print(int(ans))
