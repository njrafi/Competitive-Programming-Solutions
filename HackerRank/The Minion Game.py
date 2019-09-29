def minion_game(string):
    vow = 'AEIOU'
    ans1 = 0
    ans2 = 0
    n = len(string)
    for i in range(n):
        if string[i] in vow:
            ans1 += n - i
        else:
            ans2 += n - i
    if(ans1==ans2):
        print('Draw')
    elif ans1 > ans2:
        print('Kevin',ans1)
    else:
        print('Stuart',ans2)
    #print(ans1)
    #print(ans2)