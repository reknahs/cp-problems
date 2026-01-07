n = int(input())
nums = [int(i) for i in input().split()]
total = 0
top = nums[0]
for i in range(1, len(nums)):
    if nums[i] < top:
        total += (top - nums[i])
    top = max(top, nums[i])
print(total)

