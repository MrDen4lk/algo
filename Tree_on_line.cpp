#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbeging(), a.rend()

struct for_tree {
    ll sum, add;
    bool upd;
};

const ll sz = (1 << 17), neutral = 0;
int n;
for_tree tree[2 * sz];

void Build(const vector<ll>& t) {
    for (int i = sz; i < 2 * sz; i++) {
        if (i - sz < n) {
            tree[i] = {t[i - sz], 0, false};
        } else {
            tree[i] = {neutral, 0, false};
        }
    }
    for (int i = sz - 1; i > 0; i--) {
        tree[i] = {tree[i * 2].sum + tree[i * 2 + 1].sum, 0, false};
    }
}

void push(int v) {
    if (tree[v].add == neutral) {
        return;
    }
    tree[2 * v].add = tree[v].add;
    tree[2 * v + 1].add = tree[v].add;
    tree[2 * v].upd = true;
    tree[2 * v + 1].upd = true;
    tree[v].upd = false;
    tree[v].add = neutral;
}

void UpdateTop(int v, int x) {
    if (tree[v].upd) {
        tree[v].sum += tree[v].add * x;
        tree[v].upd = false;
    }
}

void UpdateLine(int v, int tl, int tr, int l, int r, int add) {
    if (l > r) {
        return;
    }
    if (tr == r && tl == l) {
        tree[v].add = add;
        tree[v].upd = true;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    UpdateLine(v * 2, tl, tm, l, min(r, tm), add);
    UpdateLine(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, add);
    tm = (tr - tl + 1) / 2;
    UpdateTop(v * 2, tm);
    UpdateTop(v * 2 + 1, tm);
    tree[v].sum = tree[v * 2].sum + tree[v * 2 + 1].sum;
    tree[v].upd = false;
}

ll GetSum(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return neutral;
    }
    if (tl == l && tr == r) {
        UpdateTop(v, tr - tl + 1);
        return tree[v].sum;
    }
    UpdateTop(v, tr - tl + 1);
    push(v);
    int tm = (tl + tr) / 2;
    return GetSum(2 * v, tl, tm, l, min(r, tm)) + GetSum(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
}

void Print() {
    for (int i = 1; i <= n; i++) {
        cout << GetSum(1, 1, sz, i, i) << ' ';
    }
    cout << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    cin >> n;
    vector<ll>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Build(a);
    cout << GetSum(1, 1, sz, 1, n) << '\n';
    UpdateLine(1, 1, sz, 1, n, 10);
    Print();
    cout << GetSum(1, 1, sz, 1, n);

    return 0;
}