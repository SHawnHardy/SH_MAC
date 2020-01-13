#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file Codeforces/613/b.py
 @author SHawnHardy
 @date 2020-01-12
 @copyright MIT License
"""

from sys import setrecursionlimit

setrecursionlimit(1000000)

t = int(input())

while t > 0:
    t -= 1
    n = int(input())
    arr = list(map(int, input().split()))
    s = sum(arr)
    tmp = 0
    try:
        for i in range(n - 1):
            tmp += arr[i]
            if tmp <= 0 or tmp >= s:
                raise ValueError
    except ValueError:
        print("NO")
    else:
        print("YES")
