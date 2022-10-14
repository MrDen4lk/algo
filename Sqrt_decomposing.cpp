#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbeging(), a.rend()

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ln = (int)sqrt(n) + 1;
    vector<int> b(ln);
    for (int i = 0; i < n; i++) {
        b[i / ln] += a[i];
    }

    int sm = 0, cr = r / ln, cl = l / ln;
    if (cr == cl) {
        for (int i = l; i <= r; i++) {
            sm += a[i];
        }
    }
    else {
        for (int i = l, end = (cl + 1) * ln - 1; i <= end; i++) {
            sm += a[i];
        }
        for (int i = cl + 1; i <= cr - 1; i++) {
            sm += b[i];
        }
        for (int i = cr * ln; i <= r; i++) {
            sm += a[i];
        }
    }
    cout << sm;

    return 0;
}