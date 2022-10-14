#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbeging, a.rend()

const int MAXN = 1e6 + 1, lg = 18;
int n, sparse[lg][MAXN], logs[MAXN];

void Build(const vector<int>& t) {
    for (int i = 0; i < len(t); i++) {
        sparse[0][i] = t[i];
    }
    int k = 1;
    for (int i = 1; i < lg; i++, k *= 2) {
        for (int j = 0; j + 2 * k <= len(t); j++) {
            sparse[i][j] = max(sparse[i - 1][j], sparse[i - 1][j + k]);
        }
    }
    logs[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        logs[i] = logs[i / 2] + 1;
    }
}

int GetMax(int l, int r) {
    int j = logs[r - l + 1];
    return max(sparse[j][l], sparse[j][r - (1 << j) + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Build(a);
    cout << GetMax(0, n - 1);

    return 0;
}