import sys

str = sys.stdin.readline().strip()

n = int(sys.stdin.readline())

words = [sys.stdin.readline().strip() for _ in range(n)]
#used = [0]*n

def cut_string(start, end) :
    
    if start == end :
        #if used.count(0) == 0 :
        print(1)
        exit()
        #else :
            #return
        
    for i in range(n) :
        word = words[i]
        if str[start:start+len(word)] == word :
            #used[i] += 1
            cut_string(start+len(word), end)
            #used[i] -= 1
    return

cut_string(0, len(str))
print(0)