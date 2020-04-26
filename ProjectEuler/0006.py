#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file ProjectEuler/0006.py
 @author SHawnHardy
 @date 2020-04-26
 @copyright MIT License
"""

import sys

sys.setrecursionlimit(1000000)

print(((1 + 100) * 100 // 2)**2 - sum([_ * _ for _ in range(1, 101)]))
# 25164150
