#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbeging(), a.rend()

struct for_tree {
    int l = -1, r = -1;
    ll up = 0, mx = 0, sz = 0;
};

int n, m, ask_left, ask_right, ask_add;
char ask;
vector<ll> t;
vector<for_tree> tree;

void build(vector<ll>& t, int v, int l, int r) {
    tree[v].r = r;
    tree[v].l = l;
    tree[v].sz = r - l + 1;
    if (l == r) {
        tree[v].mx = t[l];
        return;
    }
    int m = (l + r) / 2;
    build(t, 2 * v, l, m);
    build(t, 2 * v + 1, min(m + 1, r), r);
    tree[v].mx = max(tree[2 * v].mx, tree[2 * v + 1].mx);
}

void push(int v) {
    if (2 * v < 4 * n && tree[2 * v].l != - 1) {
        tree[2 * v].up += tree[v].up;
    }
    if (2 * v + 1 < 4 * n && tree[2 * v + 1].l != -1) {
        tree[2 * v + 1].up += tree[v].up;
    }
    tree[v].mx += tree[v].up;
    tree[v].up = 0;
}

void update(int l, int r, ll add, int v = 1) {
    push(v);
    if (tree[v].l == l && tree[v].r == r) {
        tree[v].up += add;
        push(v);
    } else if (l <= r) {
        int m = (tree[v].l + tree[v].r) / 2;
        if (2 * v < 4 * n) {
            update(l, min(m, r), add, 2 * v);
        }
        if (2 * v + 1 < 4 * n) {
            update(max(m + 1, l), r, add, 2 * v + 1);
        }
        if (2 * v + 1 < 4 * n) {
            tree[v].mx = max(tree[2 * v].mx, tree[2 * v + 1].mx);
        }
    }
}

ll get_max(int l, int r, int v = 1) {
    push(v);
    if (tree[v].l == l && tree[v].r == r) {
        return tree[v].mx;
    } else if (l <= r) {
        int m = (tree[v].l + tree[v].r) / 2;
        return max(get_max(l, min(m, r), 2 * v), get_max(max(m + 1, l), r, 2 * v + 1));
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    t.resize(n);
    tree.resize(4 * n);
    for (auto& val : t) {
        cin >> val;
    }
    build(t, 1, 0, n - 1);
    cin >> m;

    while (m--) {
        cin >> ask >> ask_left >> ask_right;
        if (ask == 'a') {
            cin >> ask_add;
            update(--ask_left, --ask_right, ask_add);
        } else {
            cout << get_max(--ask_left, --ask_right) << ' ';
        }
    }

    return 0;
}
