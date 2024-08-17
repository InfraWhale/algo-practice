import sys
# 개념 봐도 모르겠음
v, e = map(int, sys.stdin.readline().split())

parents = [i for i in range 1, v+1]
edges = []
stack = []

for _ in range (e) :
    a, b, c = map(int, sys.stdin.readline().split())
    edges.append((a, b, c))

edges.sort(key=lambda x:x[2])

for i in range(e) :
    parent, child, add = edges[i]
    if parent < child :
        parent, child = child, parent
    
    if child == parents[parent] :
        
    
    
    
    
while True :
    

# for i in range(v) :
#     visited[i] = 1
#     go(i, 0, 0)
#     visited[i] = 0

# print(min_val)