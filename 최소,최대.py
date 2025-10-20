#½ÃÇè°øºÎ¶«¿¡ ÆÄÀÌ½ã º¹±âÇØ¾ßµÊ;

def myMax(nums):
    maximum = nums[0]
    for i in nums:
        if maximum < i:
            maximum = i
    return maximum

def myMin(nums):
    minimum = nums[0]
    for i in nums:
        if minimum > i:
            minimum = i
    return minimum

n = int(input())
nums = list(map(int, input().split()))

maximum = myMax(nums)
minimum = myMin(nums)

print(minimum, maximum)