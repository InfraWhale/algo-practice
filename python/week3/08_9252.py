import sys
# 94% 시간초과 -> 길이를 저장하는 배열과 문자열을 저장하는 배열을 따로 뒀었는데 길이 저장하는 배열을 삭제해서 해결

s1 = sys.stdin.readline().strip()
s2 = sys.stdin.readline().strip()

lcs_str = [['' for x in range(len(s2)+1)] for y in range(len(s1)+1)]

max_idx = (0, 0)

for i in range(len(s1)) :
    for j in range(len(s2)) :
        if s1[i] == s2[j] :
            lcs_str[i+1][j+1] = lcs_str[i][j] + s1[i]
            
            if len(lcs_str[i+1][j+1]) > len(lcs_str[max_idx[0]][max_idx[1]]) :
                max_idx = (i+1, j+1)
        else :
            if len(lcs_str[i+1][j]) > len(lcs_str[i][j+1]) :
                lcs_str[i+1][j+1] = lcs_str[i+1][j]
            else :
                lcs_str[i+1][j+1] = lcs_str[i][j+1]
    
# for i in range (len(s1)+1) :
#     print (lcs_str[i])

result = lcs_str[max_idx[0]][max_idx[1]]

print(len(result))
print(result)