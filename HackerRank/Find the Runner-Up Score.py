if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    arr = list(arr)
    arr.sort()
    last = arr[-1]
    while arr[-1]==last:
        arr.pop()
    print(arr[-1])