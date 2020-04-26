#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file ProjectEuler/0001.py
 @author SHawnHardy
 @date 2020-04-25
 @copyright MIT License
"""

import sys

sys.setrecursionlimit(1000000)

print(
    sum(range(3, 1000, 3)) + sum(range(5, 1000, 5)) - sum(range(15, 1000, 15)))
# 233168
