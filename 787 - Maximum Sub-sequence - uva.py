# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
dp=[[]]
length = 0
a = []

def f(idx , mode) :
    if idx == length:
        return mode
    if not (dp[idx][mode] == -1) :
        return dp[idx][mode]
    if(a[idx] == 0) :
        return 0
    res = 0
    if(mode == 1) :
        if(a[idx] > 0) :
            res = a[idx]*f(idx + 1 , 1)
        else :
            res = a[idx] * f(idx + 1 , 0)
    else :
        if(a[idx] > 0) :
            res = a[idx] * f(idx + 1 , 0)
        else :
            res = a[idx] * f(idx + 1, 1)
    if mode == 0 and res == 0 and a[idx] < 0:
        res = a[idx]
    if mode == 1 and res == 0 and a[idx] > 0:
        res = a[idx]
    dp[idx][mode] = res
    return res

while True :
    try :
        #a =[int(x) for x in input().split()]
        a = list(map(int,input().split()))
        a = a[:-1]
        length = len(a)
        dp = [[-1 for x in range(2)] for j in range(length)]
        ans = f(0 , 1)
        for i in range(length):
            ans = max(ans, f(i , 1))
        if ans == 0 :
            ans = max(a)
        print(ans)
    except EOFError :
        break

