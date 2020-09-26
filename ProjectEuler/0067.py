#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file ProjectEuler/0067.py
 @author SHawnHardy
 @date 2020-04-27
 @copyright MIT License
"""

import sys

sys.setrecursionlimit(1000000)

ans = []
with open('./input/p067_triangle.txt', 'r') as file:
    for row in file:
        row = list(map(int, row.split(' ')))
        try:
            ans.append(ans[-1] + row[-1])
        except IndexError:
            ans.append(row[-1])
            continue
        for i in range(len(row) - 2, 0, -1):
            ans[i] = max(ans[i], ans[i - 1]) + row[i]
        ans[0] += row[0]

print(max(ans))
# 7273
