#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file Codeforces/612/div2_a.py
 @author SHawnHardy
 @date 2020-01-07
 @copyright MIT License
"""

for t in range(int(input())):
    k = int(input())
    s = input()
    ans = 0
    left_A = -1
    while True:
        pos = s.find('A', left_A + 1)
        if pos == -1:
            break
        if left_A != -1:
            ans = max(ans, pos - 1 - left_A)
        left_A = pos
    if left_A != -1:
        ans = max(ans, len(s) - 1 - left_A)
    print(ans)
