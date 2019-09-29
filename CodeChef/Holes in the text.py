__author__ = 'NJRafi'
t = int(raw_input())
for j in range(t):
    inp = raw_input()
    count = 0
    for i in inp:
        if i=='A' or i=='D' or i=='O' or i=='P' or i=='R' or i=='Q':
            count += 1
        elif i=='B':
            count += 2
    print count