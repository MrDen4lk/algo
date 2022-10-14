#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbeging(), a.rend()

const int MAXN = 1e6 + 1;
vector<int> graph[MAXN];
bool used[MAXN];

inline void DFS(int v, int pred) {
    used[v] = true;
    for (auto i : graph[v]) {
        if (i == pred) {
            continue;
        }
        if (!used[i]) {
            DFS(i, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        a--; b--;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    DFS(1, -1);

    return 0;
}