#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbeging(), a.rend()

struct for_tree {
    int val = 0;
};

const int sz = (1 << 17);
int n;
for_tree tree[4 * sz];

void build(vector<int>& t, int v, int l, int r) {
    if (l == r) {
        tree[v].val = t[l];
    } else {
        int m = (l + r) / 2;
        build(t, 2 * v, l, m);
        build(t, 2 * v + 1, m + 1, r);
        tree[v].val = tree[2 * v].val + tree[2 * v + 1].val;
    }
}

void update(int v, int l, int r, int pos, int val) {
    if (l == r) {
        tree[v].val = val;
    } else {
        int m = (l + r) / 2;
        if (pos <= m) {
            update(2 * v, l, m, pos, val);
        } else {
            update(2 * v + 1, m + 1, r, pos, val);
        }
        tree[v].val = tree[2 * v].val + tree[2 * v + 1].val;
    }
}

int get_sum(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (tl == l && tr == r) {
        return tree[v].val;
    }
    int tm = (tl + tr) / 2;
    return get_sum(2 * v, tl, tm, l, min(tm, r)) + get_sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(a);
    cout << get_sum(1, 0, n - 1, 0, n - 1);

    return 0;
}
