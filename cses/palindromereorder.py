start = input()
alpha = dict()
for i in start:
    if i in alpha:
        alpha[i] += 1
    else:
        alpha[i] = 1
oddnum = 0
for i in alpha:
    oddnum += alpha[i]%2 == 1
if oddnum > 1:
    print("NO SOLUTION")
else:
    ans = ""
    odd = None
    for i in alpha:
        if alpha[i]%2 == 1:
            odd = i
        else:
            ans += i*(alpha[i]//2)
    reverse = ans[::-1]
    if odd is not None:
        ans += odd*alpha[odd]
    ans += reverse
    print(ans)
