/*
 * @file Codeforces/613/d.cpp
 * @author SHawnHardy
 * @date 2020-01-13
 * @copyright MIT License
 * @templates Trie-0.2
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

struct Trie {
    const static int TRIE_SIZE = 2;

    struct Trie_Node {
        int cnt;
        Trie_Node *next[TRIE_SIZE];
    };

    int trie_convert(char c) { return c - '0'; }

    Trie_Node *head;

    Trie_Node *init_node() {
        Trie_Node *rst = (Trie_Node *)malloc(sizeof(Trie_Node));
        rst->cnt = 0;
        for (int i = 0; i < TRIE_SIZE; i++) {
            (rst->next)[i] = NULL;
        }
        return rst;
    }

    Trie() { head = init_node(); }

    void add(char str[]) {
        Trie_Node *p = head;
        (p->cnt)++;
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            Trie_Node **next = &((p->next)[trie_convert(str[i])]);
            if (!(*next)) {
                *next = init_node();
            }
            ((*next)->cnt)++;
            p = *next;
        }
    }
};

int solve(Trie::Trie_Node *p, int len) {
    int ans = 0;

    while (len && ((p->next[0] == NULL && p->next[1] != NULL) ||
                   (p->next[0] != NULL && p->next[1] == NULL))) {
        ans <<= 1;
        len--;
        p = (p->next[0] == NULL ? p->next[1] : p->next[0]);
    }
    if (len) {
        ans <<= 1;
        ans += 1;
        ans <<= (--len);
        ans += min(solve(p->next[0], len), solve(p->next[1], len));
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    Trie t;

    int n;
    cin >> n;
    char str[30 + 10];
    str[30] = '\0';
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < 30; j++) {
            str[j] = ((a & (1 << (29 - j))) > 0) ? '1' : '0';
        }
        t.add(str);
    }

    cout << solve(t.head, 30) << endl;

    return 0;
}