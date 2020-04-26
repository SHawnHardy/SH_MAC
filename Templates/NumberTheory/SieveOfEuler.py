#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file Templates/NumberTheory/SieveOfEuler.py
 @version 0.3
 @author SHawnHardy
 @date 2020-04-26
 @copyright MIT License
 @last_used ProjectEuler/0012.py
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
