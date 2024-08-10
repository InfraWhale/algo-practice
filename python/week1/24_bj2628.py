import sys
w_max, h_max = 0, 0
w_end, h_end = map(int,sys.stdin.readline().split())

h_arr = [0, h_end]
w_arr = [0, w_end]

a = int(sys.stdin.readline())

for i in range (a) :
    way, no = map(int,sys.stdin.readline().split())
    if way == 0 :
        h_arr.append(no)
    if way == 1 :
        w_arr.append(no)

h_arr.sort()
w_arr.sort()

for i in range (len(h_arr)-1) :
    h_len = h_arr[i+1] - h_arr[i]
    if h_len > h_max :
        h_max = h_len
        
for i in range (len(w_arr)-1) :
    w_len = w_arr[i+1] - w_arr[i]
    if w_len > w_max :
        w_max = w_len

print((w_max)*(h_max))
