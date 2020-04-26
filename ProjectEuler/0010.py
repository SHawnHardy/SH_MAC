#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file ProjectEuler/0010.py
 @author SHawnHardy
 @date 2020-04-25
 @copyright MIT License
 @templates NumberTheory/SieveOfEuler.py-0.2
"""

import sys

sys.setrecursionlimit(1000000)


def sieve_of_euler(limit):
    is_prime = [True for _ in range(limit)]
    prime = []
    for x in range(2, limit):
        if is_prime[x]:
            prime.append(x)

        for p in prime:
            if p * x >= limit:
                break
            is_prime[p * x] = False
            if x % p == 0:
                break
    return is_prime, prime


print(sum(sieve_of_euler(2000000)[1]))
# 142913828922
