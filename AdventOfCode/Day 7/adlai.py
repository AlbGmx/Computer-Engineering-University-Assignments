import copy
import re
import time

f = open('input.txt').read().strip().split('\n')
f_splitted = [l.split(': ') for l in f]
parsed = []
for l in f:
    r,n = l.split(': ')
    n = [int(v) for v in n.split()]
    parsed.append([int(r),n])

result = 0

def inc_mask(array):
   array[0] += 1
   for index in range(len(array)-1):
        if array[index] != 3:
            break
        array[index] = 0
        array[index+1] += 1

def calculate_good(nums:list, mask:list):
    r = nums[0]
    for i, n in enumerate(mask):
        # if n == 0:
        #     r = r + nums[i+1]
        #     n_is_zro_cnt += 1
        # elif n == 1:
        if n == 1:
            n_is_one_cnt += 1
            r = r * nums[i+1]
        # else:
        elif n == 2:
            n_is_two_cnt += 1
            r = int(str(r) + str(nums[i+1]))
        else:
            n_is_zro_cnt += 1
            r = r + nums[i+1]
    return r

def is_valid(nums:list,r:int):
    mask = [0] * (len(nums)-1)
    limit = 3**(len(nums) - 1)

    for _ in range(limit):
        calc = nums[0]
        for i, n in enumerate(mask):
            if n == 0:
                calc = calc + nums[i+1]
            elif n == 1:
                calc = calc * nums[i+1]
            else: # n == 0
                calc = int(str(calc) + str(nums[i+1]))
        if calc == r:
            return True
        inc_mask(mask)

    return False

to_repeat = 10
avg = 0
for _ in range(to_repeat):
    start_time = time.time()
    for l in parsed:
        r,nums = l
        if is_valid(nums,r):
            result += r
    end_time = time.time() 
    # print(result)
    result = 0
    # print(end_time - start_time)
    avg += end_time - start_time
print(avg/to_repeat)