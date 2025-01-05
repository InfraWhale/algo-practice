import sys

n, m = map(int, sys.stdin.readline().split())

arr = []
arr_house = []
arr_shop = []

for i in range(n) :
    arr.append(list(map(int,sys.stdin.readline().split())))
    for j in range(n) :
        if arr[i][j] == 1 :
            arr_house.append((i, j))
        elif arr[i][j] == 2 :
            arr_shop.append((i, j))
            
arr_alive = []
ret = 987654321
def chicken(idx, depth) :
    global ret
    if depth == m :
        ret_can = 0
        for house in arr_house :
            dist = 987654321
            for alive in arr_alive :
                dist = min(dist, abs(house[0] - alive[0]) + abs(house[1] - alive[1]))
            ret_can += dist
        ret = min(ret, ret_can)
        return

    for i in range (idx+1, len(arr_shop)) :
        arr_alive.append(arr_shop[i])
        chicken(i, depth+1)
        arr_alive.pop()
    return

chicken(-1, 0)

print(ret)