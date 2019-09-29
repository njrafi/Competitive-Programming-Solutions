def wrap(string, max_width):
    gg = ''
    tem = ''
    for i in string:
        tem += i
        if(len(tem)==max_width):
            gg += tem
            gg += '\n'
            tem = ''
    if(len(tem)>0):
        gg += tem
        gg += '\n'
        tem = ''
    return gg