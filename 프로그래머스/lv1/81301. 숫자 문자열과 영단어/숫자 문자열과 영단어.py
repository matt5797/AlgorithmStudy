def solution(s):
    nums = ('zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine')
    for i in range(10):
        s = s.replace(nums[i], str(i))
    return int(s)
