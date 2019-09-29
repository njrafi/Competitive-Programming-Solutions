#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    s = input()
    cnt = {}
    v = []
    for i in s:
        if ord(i) in cnt:
            cnt[ord(i)] = cnt[ord(i)] + 1
        else:
            cnt[ord(i)] = 1
    #print(ord('a'))
   # print(ord('z'))
    for i in range(ord('a'),ord('z')+1):
            if i in cnt:
                v.append((-cnt[i],i))
    v.sort()
   # print(v)
    for i in range(3):
        print(chr(v[i][1]),-v[i][0])
