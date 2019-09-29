def count_substring(string, sub_string):
    ans = 0
    for i in range(len(string)):
        tem = ''
        for j in range(i,len(string)):
            tem += string[j]
            if(len(tem)==len(sub_string)):
                break
        if(tem==sub_string):
            ans = ans + 1
    return ans