if __name__ == '__main__':
    s = input()
    ok = 0;
    for i in s:
        if i.isalnum():
            print('True')
            ok = 1
            break
    if ok==0:
        print('False')
    
    ok = 0;
    for i in s:
        if i.isalpha():
            print('True')
            ok = 1
            break
    if ok==0:
        print('False')
        
    ok = 0;
    for i in s:
        if i.isdigit():
            print('True')
            ok = 1
            break
    if ok==0:
        print('False')
    
    ok = 0;
    for i in s:
        if i.islower():
            print('True')
            ok = 1
            break
    if ok==0:
        print('False')
    
    ok = 0;
    for i in s:
        if i.isupper():
            print('True')
            ok = 1
            break
    if ok==0:
        print('False')