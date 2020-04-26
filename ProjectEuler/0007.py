#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file ProjectEuler/0007.py
 @author SHawnHardy
 @date 2020-04-26
 @copyright MIT License
 @templates NumberTheory/SieveOfEuler.py-0.3
"""

import sys

sys.setrecursionlimit(1000000)


def sieve_of_euler(limit):
    prime = []
    is_prime = [True for _ in range(limit)]
    is_prime[0] = is_prime[1] = False
    prime_factor = [_ for _ in range(limit)]

    for x in range(2, limit):
        if is_prime[x]:
            prime.append(x)

        for p in prime:
            if p * x >= limit:
                break
            is_prime[p * x] = False
            prime_factor[p * x] = p
            if x % p == 0:
                break
    return prime, is_prime, prime_factor


print(sieve_of_euler(1000000)[0][10000])
# 104743
