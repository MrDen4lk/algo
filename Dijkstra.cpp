#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbeging(), a.rend()

const int MAXN = 1e2 + 1;
const ll INF = 1e9;
int dist[MAXN], n, pred[MAXN];
vector<pair<int, int>> graph[MAXN];
vector<int> way;
set <pair<int, int>> check;

void dijkstra(int st) {
    check.insert({0, st});
    dist[st] = 0;
    pred[st] = INF;
    while (check.size()) {
        pair<int, int> f = *check.begin();
        st = f.second;
        check.erase(check.begin());
        for (auto v : graph[st]) {
            if (dist[v.first] > dist[st] + v.second) {
                pred[v.first] = st;
                check.erase({dist[v.first], v.second});
                dist[v.first] = dist[st] + v.second;
                check.insert({dist[v.first], v.first});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m, v, u;
    cin >> n >> m >> v >> u;
    v--; u--;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        a--; b--;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    for (int i = 1; i < MAXN; i++) {dist[i] = INF;}
    dijkstra(v);
    int x = u;
    while (pred[x] != INF) {
        way.emplace_back(x);
        x = pred[x];
    }
    way.emplace_back(v);
    reverse(all(way));
    cout << len(way) - 1 << ' ' << dist[u] << '\n';
    for (const auto& i : way) {
        cout << i << ' ';
    }

    return 0;
}