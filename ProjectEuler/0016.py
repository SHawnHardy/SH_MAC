#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file ProjectEuler/0016.py
 @author SHawnHardy
 @date 2020-04-27
 @copyright MIT License
"""

import sys

sys.setrecursionlimit(1000000)

print(sum(map(int, list(str(2 ** 1000)))))
# 1366
