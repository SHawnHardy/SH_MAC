#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file Templates/NumberTheory/PrimeActorization.py
 @version 0.2
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

    while x != 1:
        rst.append([prime_factor[x], 0])
        while x % rst[-1][0] == 0:
            x //= prime_factor[x]
            rst[-1][1] += 1
    return rst
