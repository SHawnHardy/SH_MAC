#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file ProjectEuler/0003.py
 @author SHawnHardy
 @date 2020-04-26
 @copyright MIT License
 @templates NumberTheory/SieveOfEuler.py-0.4,
 NumberTheory/PrimeActorization.py-0.2
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


prime, _, prime_factor = sieve_of_euler(1000000)
print(prime_actorization(600851475143, prime, prime_factor)[-1][0])
# 6857
