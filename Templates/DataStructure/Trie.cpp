/*
 * @file Templates/DataStructure/Trie.cpp
 * @version 0.1
 * @author SHawnHardy
 * @date 2020-01-07
 * @copyright MIT License
 * @last_used Codeforces/612/div2_b.cpp
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
    const static int TRIE_SIZE = 26;

    struct Trie_Node {
        int cnt;
        Trie_Node *next[TRIE_SIZE];
    };

    int trie_convert(char c) { return c - 'a'; }

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