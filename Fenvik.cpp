#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbeging(), a.rend()

vector<int> t;
int n;

void init(int nn) {
	n = nn;
	t.assign (n, 0);
}

int sum(int r) {
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

void inc(int i, int delta) {
	for (; i < n; i = (i | (i+1)))
		t[i] += delta;
}

int sum(int l, int r) {
	return sum (r) - sum (l-1);
}

void init(vector<int> a) {
	init (len(a));
	for (unsigned i = 0; i < len(a); i++)
		inc (i, a[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    return 0;
}