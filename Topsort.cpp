#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbeging(), a.rend()

const int MAXN = 1e3 + 1;
vector<int> graph[MAXN];
vector<int> topsort;
bool used[MAXN];

inline void tpsort(int32 v) {
    used[v] = true;
    for (auto i : graph[v]) {
        if (!used[i]) {
            tpsort(i);
        }
    }
    topsort.emplace_back(v);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (size_t i = 0; i < m; i++) {
        int a, b;
        a--; b--;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    tpsort(0);
    for (const auto& i : topsort) {cout << i << ' ';}

    return 0;
}