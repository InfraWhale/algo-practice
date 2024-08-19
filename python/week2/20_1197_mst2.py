# 크루스칼로 구현

v, e = map(int, input().split())

edges = [list(map(int, input().split())) for _ in range(e)]
edges.sort(key=lambda x: x[-1]) # 가중치 기준 정렬해주기

parent = [i for i in range(v+1)] # 초기화

# print(edges)
# print(parent)

def get_parent(x):
    if parent[x] == x: # 부모가 자기 자신이다 -> 루트이다.
        return x
    parent[x] = get_parent(parent[x])
    return parent[x]

def union_parent(a, b): # 수가 더 큰 쪽의 부모를, 작은쪽의 부모로 바꾼다 -> 두 간선을 합친다.
    a_root = get_parent(a)
    b_root = get_parent(b)
    if a_root < b_root:
        parent[b_root] = a_root
    else:
        parent[a_root] = b_root

def same_parent(a, b):
    return get_parent(a) == get_parent(b)

result = 0

for a, b, cost in edges:
    if not same_parent(a, b): # 부모가 같다 -> 사이클이 형성되는 것. 부모가 같지 않은 경우에만 한다.
        union_parent(a, b)
        result += cost

print(result)