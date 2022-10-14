#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int) a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

vector<int> z_func(string s) {
    vector<int> z(len(s));
    int r = 0, l = 0;
    for (int i = 1; i < len(s); i++) {
        if (i <= r) {
            z[i] = min(z[i -l], r - i + 1);
        }
        while (i + z[i] < len(s) && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;
    vector<int> ans = z_func(s);
    ans[0] = len(s);
    for (const auto& i : ans) {
        cout << i << ' ';
    }

    return 0;
}