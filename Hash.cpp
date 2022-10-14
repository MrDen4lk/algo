#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbeging(), a.rend()

const ll base = 43;

void Hash(string& s, vector<ll>& pow, vector<ll>& res, ll mod) {
    size_t n = len(s);
    pow.resize(n + 1);
    res.resize(n + 1);
    res[0] = 0;
    pow[0] = 1;
    for (size_t i = 0; i < n; i++) {
        pow[i + 1] = pow[i] * base % mod;
        res[i + 1] = (res[i] * base % mod + s[i]) % mod;
    }
}

ll GetHash(vector<ll>& input, vector<ll>& pow, int start, int finish, ll mod) {
    if (start > finish) {
        return 0;
    }
    return ((input[finish + 1] - input[start] * pow[finish - start + 1] % mod) + mod) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    string s, t;
    cin >> s >> t;
    vector<ll> hs1, pow1, hs2, pow2;
    ll mod = 1e9 + 7;
    Hash(s, pow1, hs1, mod);
    Hash(t, pow2, hs2, mod);
    cout << GetHash(hs1, pow1, 0, len(s) - 1, mod) << ' ' << GetHash(hs2, pow2, 0, len(t) - 1, mod);

    return 0;
}