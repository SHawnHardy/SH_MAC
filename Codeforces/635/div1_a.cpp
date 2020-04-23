/*
 * @file Codeforces/635/div1_a.cpp
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

const int MAXN = 200000 + 10;
const int MOD = 1E9 + 7;
const int INF = 0x3f3f3f3f;

int n, k;
vector<int> G[MAXN];
int num_son[MAXN];
int num_des[MAXN];
int fa[MAXN];
int dis[MAXN];

bool vis[MAXN];

priority_queue<pii> pq;

int dfs(int nd, int ds) {
    vis[nd] = true;
    dis[nd] = ds;
    int rt = 0;
    for (auto i = G[nd].begin(); i != G[nd].end(); i++) {
        int t = *i;
        if (vis[t])
            continue;
        else {
            num_son[nd]++;
            fa[t] = nd;
            rt += dfs(t, ds + 1);
        }
    }

    num_des[nd] = rt;
    if (num_son[nd] == 0) {
        pq.push(make_pair(ds - num_des[nd], nd));
    }
    return num_des[nd] + 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    memset(num_son, 0, sizeof(num_son));
    memset(num_des, 0, sizeof(num_des));
    memset(vis, 0, sizeof(vis));
    cin >> n >> k;
    for (int i = 0; i < (n - 1); i++) {
        int s, t;
        cin >> s >> t;
        G[s].pb(t);
        G[t].pb(s);
    }
    fa[1] = 0;
    dfs(1, 0);

    ll ans = 0;
    while (k--) {
        pii t = pq.top();
        pq.pop();
        ans += t.fi;
        int f = fa[t.se];
        num_son[f]--;
        if (num_son[f] == 0) {
            pq.push(make_pair(dis[f] - num_des[f], f));
        }
    }

    cout << ans << endl;
    return 0;
}