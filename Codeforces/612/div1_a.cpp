/*
 * @file Codeforces/612/div1_a.cpp
 * @author SHawnHardy
 * @date 2020-01-08
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

const int MAXN = 200 + 10;
const int MOD = 1E9 + 7;
const int INF = 0x3f3f3f3f;

int row[MAXN];
int dp[2][2][MAXN];
int dp_flag = 0;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    cin >> n;
    int blank = 0;
    int odd = (n + 1) / 2;

    for (int i = 0; i < n; i++) {
        cin >> row[i];
        if (!row[i]) {
            blank++;
        }
        if (row[i] & 1) {
            odd--;
        }
    }

    int ans_fix = 0;

    memset(dp, 0x3f, sizeof(dp));
    int last_fill = 0;

    if (row[0] == 0) {
        if (blank > odd) {
            dp[dp_flag][0][odd] = 0;
        }
        dp[dp_flag][1][odd - 1] = 0;
        last_fill = 0;
    } else {
        dp[dp_flag][0][odd] = 0;
        dp[dp_flag][1][odd] = 0;
        last_fill = -2;
    }

    for (int i = 1; i < n; i++) {
        bool flag = ((i - last_fill) == 1);

        if (row[i] == 0) {
            for (int j = 0; j <= odd; j++) {
                // even
                if (blank > j) {
                    dp[dp_flag ^ 1][0][j] =
                        min(dp[dp_flag][0][j], dp[dp_flag][1][j] + (int)flag) +
                        (flag ? 0 : (row[i - 1] & 1));
                }
                // odd
                dp[dp_flag ^ 1][1][j] = min(dp[dp_flag][0][j + 1] + (int)flag,
                                            dp[dp_flag][1][j + 1]) +
                                        (flag ? 0 : ((row[i - 1] & 1) ^ 1));
            }

            last_fill = i;
            dp_flag ^= 1;
        } else if (flag) {
            for (int j = 0; j <= odd; j++) {
                dp[dp_flag][(row[i] & 1) ^ 1][j] =
                    min(dp[dp_flag][(row[i] & 1) ^ 1][j] + 1, INF);
            }
        } else {
            if ((row[i] & 1) ^ (row[i - 1] & 1)) {
                ans_fix++;
            }
        }
    }
    cout << min(dp[dp_flag][0][0], dp[dp_flag][1][0]) + ans_fix << endl;
    return 0;
}