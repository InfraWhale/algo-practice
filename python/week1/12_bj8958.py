a = int(input())

for i in range(a) :
    str = input()
    score = 0
    prev = 0
    for j in range(len(str)) :
        if str[j] == 'O' :
            prev += 1
            score += prev
        else :
            prev = 0
    print(score)