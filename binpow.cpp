#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int) a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

ll binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int a, n;
    cin >> a >> n;
    cout << binpow(a, n);

    return 0;
}