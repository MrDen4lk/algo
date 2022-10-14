#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbeging(), a.rend()

const int MAXN = 1e3 + 1;
const ll INF = 1e9 + 7;
vector<int> graph[MAXN];
bool used[MAXN];
int deep[MAXN], dp[MAXN], timer = 0;
set <pair<int, int>> bridges;

void find_bridges(int v, int pred) {
    used[v] = true;
    deep[v] = dp[v] = timer++;
    for (auto i : graph[v]) {
        if (i == pred) {
            continue;
        }
        if (used[i]) {
            dp[v] = min(dp[v], deep[i]);
        } else {
            find_bridges(i, v);
            dp[v] = min(dp[v], dp[i]);
            if (dp[i] > deep[v]) {
                bridges.insert({i, v});    
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            find_bridges(i, -1);
        }
    }

    for (const auto& i : bridges) {
        cout << i.first << ' ' << i.second << '\n';
    }

    return 0;
}