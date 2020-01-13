#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file Templates/NumberTheory/SieveOf
 @version 0.1
 @author SHawnHardy
 @date 2020-01-12
 @copyright MIT License
 @last_used Codeforces/613/c.py
"""

import sys

sys.setrecursionlimit(1000000)

def sieve_of_euler(limit):
    is_prime = [True for _ in range(limit + 1)]
    prime = []
    for x in range(2, limit + 1):
        if is_prime[x]:
            prime.append(x)

        for p in prime:
            if p * x >= limit:
                break
            is_prime[p * x] = False
            if x % p == 0:
                break
    return prime
