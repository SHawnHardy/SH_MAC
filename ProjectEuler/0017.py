#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file ProjectEuler/0017.py
 @author SHawnHardy
 @date 2020-04-27
 @copyright MIT License
"""

import num2words  # non-built-in
import string
import sys

sys.setrecursionlimit(1000000)

print(sum(map(
    lambda x: len([_ for _ in num2words.num2words(x)
                   if _ in string.ascii_letters]),
    range(1, 1001))))
# 21124
