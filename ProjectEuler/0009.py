#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file ProjectEuler/0009.py
 @author SHawnHardy
 @date 2020-04-26
 @copyright MIT License
"""

import sys

sys.setrecursionlimit(1000000)

for a in range(1, 1000 // 3 + 1):
    for b in range(a + 1, (1000 - a) // 2 + 1):
        c = 1000 - a - b
        if a * a + b * b == c * c:
            print(a * b * c)
            # 31875000
            exit(0)
