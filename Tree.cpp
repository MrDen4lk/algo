#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbeging(), a.rend()

struct for_tree {
    ll sum;
};

const int sz = (1 << 17), neutral = 0;
int n;
for_tree tree[2 * sz];

void Build(vector<ll>& t) {
    for (int i = sz; i < sz * 2; i++) {
        if (i - sz < n) {
            tree[i].sum = {t[i - sz]};
        } else {
            tree[i].sum = {neutral};
        }
    }
    for (int i = sz - 1; i > 0; i--) {
        tree[i].sum = tree[2 * i].sum + tree[2 * i + 1].sum;
    }
}

void Update(int ind, int val) {
    ind -= sz;
    tree[ind].sum = val;
    while (ind > 1) {
        ind /= 2;
        tree[ind].sum = tree[2 * ind].sum + tree[2 * ind + 1].sum;
    }
}

ll GetSum(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return neutral;
    }
    if (tl == l && tr == r) {
        return tree[v].sum;
    }
    int tm = (tl + tr) / 2;
    return GetSum(2 * v, tl, tm, l, min(r, tm)) + GetSum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    cin >> n;
    vector<ll> a(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    Build(a);
    cout << GetSum(1, 1, sz, 1, n);

    return 0;
}