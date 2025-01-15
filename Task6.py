#программа принимает два числа и выводит последнее из них 


n = int(input())
arr = list(map(int, input().split()))

count_dict = {}
max_count = 0
result = None

for num in arr:
    if num in count_dict:
        count_dict[num] += 1
    else:
        count_dict[num] = 1

    if count_dict[num] > max_count:
        max_count = count_dict[num]
        result = num
    elif count_dict[num] == max_count and num > result:
        result = num

print(result)