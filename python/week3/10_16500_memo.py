import sys

str = sys.stdin.readline().strip()

n = int(sys.stdin.readline())

words = [sys.stdin.readline().strip() for _ in range(n)]

length = len(str)

dp = [0] * (length + 1)
dp[0] = 1

for i in range (1, length + 1) :
    
    for word in words :
        if len(word) > i :
            continue
        #print("i, word, str[i-len(word)+1 : i]", i, word, str[i-len(word) : i])
        if dp[i - len(word)] == 1 and str[i-len(word) : i] == word :
            dp[i] = 1

print(dp[length])