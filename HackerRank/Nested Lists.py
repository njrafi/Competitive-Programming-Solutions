if __name__ == '__main__':
    v = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        v.append((score,name))
    v.sort()
    mn = v[0][0]
    mn2 = -1
    for i in v:
        if i[0] != mn:
            if mn2 == -1:
                mn2 = i[0]
            if i[0] == mn2:
                print(i[1])
        
            