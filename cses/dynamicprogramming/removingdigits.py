num = int(input())
dp = [10000000 for i in range(num)]
dp[0] = num
answer = None
for i in range(1, num):
    for j in str(dp[i-1]):
        dp[i] = min(dp[i], dp[i-1]-int(j))
    if dp[i] == 0:
        answer = i
        break
print(answer)
    
