/*
 * @file Codeforces/635/div1_b.cpp
 * @author SHawnHardy
 * @date 2020-04-16
 * @copyright MIT License
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

const int MAXN = 100000 + 10;
const int MOD = 1E9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
inline ll sqr(ll x) { return x * x; }

ll w[3][MAXN];

ll func(int a, int b, int c) {
    ll rt = INF;
    for (int i = 1; i <= w[a][0]; i++) {
        ll trt = 0;
        if (w[b][1] > w[a][i])
            continue;
        if (w[c][w[c][0]] < w[a][i])
            break;
        ll bb = *(upper_bound(w[b] + 1, w[b] + w[b][0] + 1, w[a][i]) - 1);
        ll cc = *lower_bound(w[c] + 1, w[c] + w[c][0] + 1, w[a][i]);
        trt += sqr(w[a][i] - bb);
        trt += sqr(cc - w[a][i]);
        trt += sqr(cc - bb);
        rt = min(rt, trt);
    }
    return rt;
}

ll solve() {
    for (int i = 0; i < 3; i++) {
        sort(w[i] + 1, w[i] + w[i][0] + 1);
    }
    ll rt = INF;
    vector<int> plan = {0, 1, 2};
    do {
        rt = min(rt, func(plan[0], plan[1], plan[2]));
    } while (next_permutation(plan.begin(), plan.end()));
    return rt;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 3; i++) {
            memset(w[i], 0, sizeof(w[i]));
        }
        cin >> w[0][0] >> w[1][0] >> w[2][0];
        for (int i = 0; i < 3; i++) {
            for (int j = 1; j <= w[i][0]; j++) {
                cin >> w[i][j];
            }
        }
        cout << solve() << endl;
    }
    return 0;
}