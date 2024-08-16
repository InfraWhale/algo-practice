import sys

n = int(sys.stdin.readline())
k = int(sys.stdin.readline())
arr = [sys.stdin.readline().strip() for i in range(n)] #comprehension 문법
use = [0 for i in range(n)]
dic = {}

def rec(idx, depth, sum):
    if(depth == k) :
        dic[int(sum)] = 1
        return
    for i in range(n) :
        if use[i] == 1 :
            continue
        new_sum = sum + arr[i]
        use[i] = 1
        rec(i+1, depth+1, new_sum)
        use[i] = 0
    return

rec(0, 0, "")

#print(dic)
print(len(dic))