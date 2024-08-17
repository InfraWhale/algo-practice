import sys

n = int(sys.stdin.readline())
tree = {}

for i in range (n) :
    root, left, right = sys.stdin.readline().split()
    tree[root] = [left, right]

str = ""

def front(root_val) :
    global str
    str += root_val
    
    left_val, right_val = tree[root_val]
    
    if left_val != '.' :
        front(left_val)
        
    if right_val != '.' :
        front(right_val)
    return

def mid(root_val) :
    global str

    left_val, right_val = tree[root_val]
    if left_val != '.' :
        mid(left_val)
        
    str += root_val
    
    if right_val != '.' :
        mid(right_val)
    return

def back(root_val) :
    global str

    left_val, right_val = tree[root_val]
    if left_val != '.' :
        back(left_val)
        
    if right_val != '.' :
        back(right_val)
        
    str += root_val
    return

front('A')
print(str)
str = ""

mid('A')
print(str)
str = ""

back('A')
print(str)
str = ""