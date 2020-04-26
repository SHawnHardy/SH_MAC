#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file ProjectEuler/0005.py
 @author SHawnHardy
 @date 2020-04-25
 @copyright MIT License
 @templates NumberTheory/Basic.py-0.1
"""

import functools
import sys

sys.setrecursionlimit(1000000)


def gcd(x, y):
    return y if x % y == 0 else gcd(y, x % y)


def lcm(x, y):
    return x // gcd(x, y) * y


print(functools.reduce(lcm, range(2, 21)))
# 232792560
