import sys
# lcs 알고리즘 참고
# https://velog.io/@emplam27/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B7%B8%EB%A6%BC%EC%9C%BC%EB%A1%9C-%EC%95%8C%EC%95%84%EB%B3%B4%EB%8A%94-LCS-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Longest-Common-Substring%EC%99%80-Longest-Common-Subsequence

s1 = sys.stdin.readline().strip()
s2 = sys.stdin.readline().strip()

lcs_matrix = [[0 for x in range(len(s2)+1)] for y in range(len(s1)+1)] # x축 y축 안맞춰서 인덱스 에러!

max_val = 0

for i in range(len(s1)) :
    for j in range(len(s2)) :
        if s1[i] == s2[j] :
            lcs_matrix[i+1][j+1] = lcs_matrix[i][j] + 1
            max_val = max(max_val, lcs_matrix[i+1][j+1])
        else :
            lcs_matrix[i+1][j+1] = max(lcs_matrix[i+1][j], lcs_matrix[i][j+1])

# for i in range (len(s1)+1) :
#     print (lcs_matrix[i])

print (max_val)