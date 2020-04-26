#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file Templates/NumberTheory/Basic.py
 @version 0.1
 @author SHawnHardy
 @date 2020-04-26
 @copyright MIT License
 @last_used ProjectEuler/0005.py
"""

import sys

sys.setrecursionlimit(1000000)


def gcd(x, y):
    return y if x % y == 0 else gcd(y, x % y)


def lcm(x, y):
    return x // gcd(x, y) * y
