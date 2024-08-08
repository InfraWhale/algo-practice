x, y, w, h = map(int, input().split())
a, b = 0, 0
if x < (w-x) :
    a = x
else :
    a = (w-x)

if y < (h-y) :
    b += y
else :
    b += (h-y)
    
print(min(a, b))