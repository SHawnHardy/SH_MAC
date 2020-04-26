/*
 * @file Codeforces/612/div2_b.cpp
 * @author SHawnHardy
 * @date 2020-01-07
 * @copyright MIT License
 * @templates DataStructure/Trie-0.1
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
    const static int TRIE_SIZE = 3;

    struct Trie_Node {
        int cnt;
        Trie_Node *next[TRIE_SIZE];
    };

    int trie_convert(char c) {
        switch (c) {
        case 'S':
            return 0;
        case 'E':
            return 1;
        case 'T':
            return 2;
        default:
            return -1;
        }
    }

    Trie_Node *head;

    Trie_Node *init_node() {
        Trie_Node *rst = (Trie_Node *)malloc(sizeof(Trie_Node));
        rst->cnt = 0;
        for (int i = 0; i < TRIE_SIZE; i++) {
            (rst->next)[i] = NULL;
        }
        return rst;
    }

    void init() { head = init_node(); }

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

char cards[1510][40];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, l;
    cin >> n >> l;

    Trie trie;
    trie.init();

    for (int i = 0; i < n; i++) {
        cin >> cards[i];
        trie.add(cards[i]);
    }

    int ans = 0;

    for (int i = 0; i < (n - 1); i++) {
        char *card_a = cards[i];

        for (int j = (i + 1); j < n; j++) {
            char *card_b = cards[j];

            Trie::Trie_Node *p = trie.head;
            int flag = true;

            for (int k = 0; k < l; k++) {
                char target = (card_a[k] == card_b[k]
                                   ? card_a[k]
                                   : ('S' + 'E' + 'T' - card_a[k] - card_b[k]));
                if ((p->next)[trie.trie_convert(target)] != NULL) {
                    p = (p->next)[trie.trie_convert(target)];
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans++;
            }
        }
    }
    cout << ans / 3 << endl;

    return 0;
}