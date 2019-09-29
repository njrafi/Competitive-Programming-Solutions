if __name__ == '__main__':
    N = int(input())
    arr = []
    for k in range(N):
        line = list(input().split())
        if line[0] == 'insert':
            idx = int(line[1])
            val = int(line[2])
           # print(idx)
           # print(val)
            arr.insert(idx,val)
        elif line[0] == 'print':
            print(arr)
        elif line[0] == 'pop':
            arr.pop()
        elif line[0] == 'remove':
            val = int(line[1])
            #print(arr)
            #print(val)
            arr.remove(val)
        elif line[0] == 'append':
            val = int(line[1])
            arr.append(val)
        elif line[0] == 'sort':
            arr.sort()
        else:
            arr.reverse()
            