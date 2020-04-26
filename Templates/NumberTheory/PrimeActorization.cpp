/*
 * @file Templates/NumberTheory/PrimeActorization.cpp
 * @version 0.1
 * @author SHawnHardy
 * @date 2020-04-26
 * @copyright MIT License
 * @last_used ProjectEuler/0003.cpp
 */

#include "algorithm"
#include "cmath"
#include "complex"
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "iostream"
#include "map"
#include "queue"
#include "set"
#include "stack"
#include "string"
#include "vector"

#define pb push_back
#define fi first
#define se second
#define dbg(...)                                                               \
    cerr << "[" << #__VA_ARGS__ ":" << (__VA_ARGS__) << "]" << endl;

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

const int MAXN = 200 + 10;
const int MOD = 1E9 + 7;
const int INF = 0x3f3f3f3f;

void prime_actorization(ll x, vector<int> prime, int prime_factor[], int limit,
                        vector<pair<ll, int>> &rst) {
    // x > 1
    rst.clear();

    for (auto i = prime.begin(); x >= limit && i != prime.end(); i++) {
        if (x % ll(*i) == 0LL) {
            rst.push_back(make_pair(ll(*i), 0));
            while (x % ll(*i) == 0LL) {
                rst.back().se++;
                x /= ll(*i);
            }
        }
    }
    if (x == 1)
        return;
    if (x >= limit) {
        rst.push_back(make_pair(x, 1));
        return;
    }

    while (x != 1) {
        rst.push_back(make_pair(ll(prime_factor[x]), 0));
        while (x % rst.back().fi == 0) {
            x /= prime_factor[x];
            rst.back().se++;
        }
    }
}