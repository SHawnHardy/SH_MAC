#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file ProjectEuler/0004.py
 @author SHawnHardy
 @date 2020-04-25
 @copyright MIT License
"""

import sys

sys.setrecursionlimit(1000000)

ans = 101 * 101
for i in range(100, 1000):
    for j in range(ans // i + 1, 1000):
        num = str(i * j)
        if num == num[::-1]:
            ans = i * j
print(ans)
# 906609
