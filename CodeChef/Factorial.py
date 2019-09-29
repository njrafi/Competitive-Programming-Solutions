__author__ = 'NJRafi'
t = int(raw_input())
while t:
    inp = int(raw_input())
    count = 0
    j = 1
    while 5**j<=inp:
        count += inp / 5**j
        j += 1
    print count
    t -= 1