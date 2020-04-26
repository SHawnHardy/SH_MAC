#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file ProjectEuler/0014.py
 @author SHawnHardy
 @date 2020-04-27
 @copyright MIT License
"""

import sys

sys.setrecursionlimit(1000000)

ans = [-1 for _ in range(1000000)]
ans[1] = 1


def solve(x):
    global ans
    if x >= 1000000:
        return 1 + (solve(x // 2) if x % 2 == 0 else solve(x * 3 + 1))
    if x < 1000000:
        if ans[x] == -1:
            ans[x] = (1 + (solve(x // 2) if x % 2 == 0 else solve(x * 3 + 1)))
        return ans[x]


ans = list(map(solve, range(1, 1000000)))
print(ans.index(max(ans)) + 1)
# 837799
