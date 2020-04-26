#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file ProjectEuler/0002.py
 @author SHawnHardy
 @date 2020-04-25
 @copyright MIT License
"""

import sys

sys.setrecursionlimit(1000000)


def gen(limit):
    a, b = 0, 1
    while b < limit:
        if b % 2 == 0:
            yield b
        a += b
        a, b = b, a


print(sum(gen(4000000)))
# 4613732
