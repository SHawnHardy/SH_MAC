#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
 @file Codeforces/613/c.py
 @author SHawnHardy
 @date 2020-01-12
 @copyright MIT License
 @templates NumberTheory/SieveOfEuler-0.1
"""

from math import sqrt
import sys

sys.setrecursionlimit(1000000)

X = int(input())
X_backup = X

limit = int(sqrt(X)) + 1
is_prime = [True for _ in range(limit)]
prime = []
factor = []
for x in range(2, limit):
    if is_prime[x]:
        prime.append(x)
        if X % x == 0:
            factor.append(1)
            while X % x == 0:
                X //= x
                factor[-1] *= x

    for p in prime:
        if p * x >= limit:
            break
        is_prime[p * x] = False
        if x % p == 0:
            break

if X != 1:
    print("%d %d\n" % (X_backup // X, X))
    sys.exit(0)

ans = X_backup
for plan in range(1 << len(factor)):
    a = 1
    for idx, val in enumerate(factor):
        if plan & (1 << idx) > 0:
            a *= val
    a = max(a, X_backup // a)
    ans = min(ans, a)
print("%d %d\n" % (X_backup // ans, ans))
