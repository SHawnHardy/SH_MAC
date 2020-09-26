#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file ProjectEuler/0015.py
 @author SHawnHardy
 @date 2020-04-27
 @copyright MIT License
"""

import scipy.special  # non-built-in
import sys

sys.setrecursionlimit(1000000)

print(int(scipy.special.comb(40, 20)))
# 137846528820
