/*
 * @file Templates/NumberTheory/SieveOfEuler.cpp
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