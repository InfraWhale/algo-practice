import sys

#혜다 풀이
input = sys.stdin.readline
N, K = map(int, input().split()) # 물건개수, 버틸수 있는 무게

save = [-1] * (K+1)
save[0] = 0
things = [list(map(int, input().split())) for _ in range(N)]

for W, V in things:
    temp = save[:]
    for i in range(K+1):
        if save[i] != -1 and i + W <= K:
            temp[i+W] = max(save[i] + V, save[i+W])
    save = temp
    
print(max(save))
