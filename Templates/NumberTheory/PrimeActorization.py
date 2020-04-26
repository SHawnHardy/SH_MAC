#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file Templates/NumberTheory/PrimeActorization.py
 @version 0.1
 @author SHawnHardy
 @date 2020-04-26
 @copyright MIT License
 @last_used ProjectEuler/0003.py
"""

import sys

sys.setrecursionlimit(1000000)


def prime_actorization(x, prime, prime_factor):
    rst = []

    for p in prime:
        if x < len(prime_factor):
            break
        if x % p == 0:
            rst.append([p, 0])
            while x % p == 0:
                rst[-1][1] += 1
                x //= p

    if x == 1:
        return rst

    if x >= len(prime_factor):
        rst.append([x, 1])
        return rst

    tmp_rst = []
    while x != 1:
        tmp_rst.append(prime_factor[x])
        x //= prime_factor[x]
    while tmp_rst:
        tmp = tmp_rst.pop()
        try:
            if rst[-1][0] == tmp:
                rst[-1][1] += 1
            else:
                rst.append([tmp, 1])
        except IndexError:
            rst.append([tmp, 1])
    return rst
