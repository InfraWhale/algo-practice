import sys # gpt 답

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

arr.sort()  # 배열을 정렬
count = 0

for k in range(n):
    target = arr[k]
    start = 0
    end = n - 1

    while start < end:
        if start == k:  # 자신의 인덱스를 건너뜀
            start += 1
            continue
        if end == k:  # 자신의 인덱스를 건너뜀
            end -= 1
            continue

        sum_val = arr[start] + arr[end]

        if sum_val == target:
            count += 1
            break
        elif sum_val < target:
            start += 1
        else:
            end -= 1

print(count)
