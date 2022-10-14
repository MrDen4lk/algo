#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbeging(), a.rend()

vector<ll> pref_function(string s) {
    int n = len(s);
    vector<ll> pref(n);
    for (int i = 1; i < n; i++) {
        int j = pref[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pref[j - 1];
        }
        if (s[i] == s[j]) {j++;}
        pref[i] = j;
    }
    return pref;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    string s, t;
    cin >> s >> t;
    vector<ll> pos, pr;
    int n = len(t), m = len(s), cnt = 0;
    pr = pref_function(t + "#" + s);
    
    for (int i = n + 1; i < n + m + 1; i++) {
        if (pr[i] == n) {
            cnt++;
            pos.push_back(i - 2 * n);
        }
    }
    cout << cnt << '\n';
    for (const auto& i : pos) {cout << i << ' ';}

    return 0;
}