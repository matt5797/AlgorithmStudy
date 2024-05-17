# import sys
# sys.stdin = open("input.txt", "r")

T = int(input())

def find_max(nums, count, memo):
    if count == 0:
        return "".join(nums)

    key = (tuple(nums), count)
    if key in memo:
        return memo[key]

    max_value = "0"

    for i in range(len(nums)):
        for j in range(i+1, len(nums)):
            if j > i:
                nums[i], nums[j] = nums[j], nums[i]
                max_value = max(max_value, find_max(nums, count-1, memo))
                nums[i], nums[j] = nums[j], nums[i]

    memo[key] = max_value
    return max_value

for test_case in range(1, T + 1):
    nums, count = input().split()

    nums = [x for x in nums]
    count = int(count)

    memo = {}
    result = find_max(nums, count, memo)

    print("#%d %s" % (test_case, result))
