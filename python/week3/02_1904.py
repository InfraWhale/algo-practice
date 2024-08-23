import sys
sys.setrecursionlimit(10**6)
n = int(sys.stdin.readline())

arr_result = [0]*n

def find_binary(no) :
    if no == 1 :
        return 1
    if no == 2 :
        return 2
    
    return ((find_binary(no-1) % 15746) + (find_binary(no-2) % 15746)) % 15746

print(find_binary(n))