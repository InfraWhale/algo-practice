import sys
# 메모리초과 ... 바꿔봐도 메모리초과
str1 = sys.stdin.readline().strip()
str2 = sys.stdin.readline().strip()

len1 = len(str1)
len2 = len(str2)

arr = [[(-1, -1) for x in range (len2)] for y in range (len1)]

max_len = 0
max_pos = (-1, -1)

for i in range (len1) :
    for j in range (len2) :
        if str1[i] == str2[j] :
            
            if arr[i-1][j-1] == (-1, -1) or i == 0 or j == 0 :
                arr[i][j] = (i, i)
                now_len = 1
            else :
                start = arr[i-1][j-1][0]
                end = i
                now_len = end - start + 1
                arr[i][j] = (start, end)
                
            if  now_len > max_len :
                max_len = now_len
                max_pos = (i, j)
                
print(max_len)

ret_start, ret_end = arr[max_pos[0]][max_pos[1]]

print(str1[ret_start:ret_end+1])