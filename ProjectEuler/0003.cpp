/*
 * @file ProjectEuler/0003.cpp
 * @author SHawnHardy
 * @date 2020-04-26
 * @copyright MIT License
 * @templates NumberTheory/SieveOfEuler.cpp-0.1,
 * NumberTheory/PrimeActorization.cpp-0.1
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

struct SieveOfEuler {
    vector<int> prime;
    bool *is_prime;
    int *prime_factor;

    SieveOfEuler(int limit) {
        prime.clear();
        is_prime = new bool[limit]{};
        memset(is_prime, -1, limit);
        is_prime[0] = is_prime[1] = false;
        prime_factor = new int[limit]{};

        for (int i = 2; i < limit; i++) {
            if (is_prime[i]) {
                prime.push_back(i);
                prime_factor[i] = i;
            }

            for (auto j = prime.begin(); j != prime.end() && (*j) * i < limit;
                 j++) {
                is_prime[(*j) * i] = false;
                prime_factor[(*j) * i] = *j;
                if (i % (*j) == 0)
                    break;
            }
        }
    }

    ~SieveOfEuler() {
        delete is_prime;
        delete prime_factor;
    }
};

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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    SieveOfEuler sieve(1000000);
    vector<pair<ll, int>> ans;
    prime_actorization(600851475143LL, sieve.prime, sieve.prime_factor, 1000000,
                       ans);
    cout << ans.back().fi;
    // 6857
    return 0;
}