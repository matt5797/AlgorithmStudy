def solution(nums):
    num_dict = {}
    for num in nums:
        if num not in num_dict.keys():
            num_dict[num] = 1
        else:
            num_dict[num] += 1
    
    return len(nums)/2 if len(num_dict) >= len(nums)/2 else len(num_dict)