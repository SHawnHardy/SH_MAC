#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file ProjectEuler/0012.py
 @author SHawnHardy
 @date 2020-04-26
 @copyright MIT License
"""

import functools
import sys

sys.setrecursionlimit(1000000)

prime = [2, 3, 5, 7, 11, 13, 17, 19, 23]
dp = [[-1 for _ in range(501)] for _ in range(10)]
dp[0][1] = 1

limit = functools.reduce(lambda x, y: x * y, prime)
print(limit)

for idx, p in enumerate(prime):
    t, ppt = 0, 1
    while ppt < limit:
        for i in range(1, 501):
            if dp[idx][i] != -1 and dp[idx][i] * ppt < limit:
                if i * (t + 1) > 500:
                    limit = dp[idx][i] * ppt
                    print(limit)
                else:
                    dp[idx + 1][i * (t + 1)] = dp[idx][i] * ppt if\
                    dp[idx + 1][i * (t + 1)] == -1 else\
                    min(dp[idx + 1][i * (t + 1)], dp[idx][i] * ppt)
        t += 1
        ppt *= p

print(limit)
