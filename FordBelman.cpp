#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbeging(), a.rend()

struct point {
    int a, b, cost;
};

const int INF = 1e9+1, MAXN = 1e6 + 1;
int n, m;
vector<point> graph;
int dist[MAXN], pred[MAXN];

void ForBel(int v) {
    for (int i = 0; i < MAXN; i++) {pred[i] = -1; dist[i] = INF;}
    dist[v] = 0;
    for(;;) {
        bool run = false;
        for (int j = 0; j < m; j++) {
            if (dist[graph[j].a] < INF) {
                if (dist[graph[j].b] > dist[graph[j].a] + graph[j].cost) {
                    dist[graph[j].b] = dist[graph[j].a] + graph[j].cost;
                    pred[graph[j].b] = graph[j].a;
                    run = true;
                }
            }
        }
        if (!run) { 
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int v, u, a, b, c;
    cin >> n >> m >> v >> u;
    v--; u--;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        graph.push_back({a, b, c});
        graph.push_back({b, a, c});
    }
    ForBel(v);
    cout << dist[u] << '\n';
    vector<int> way;
    int x = u;
    while (x != -1) {
        way.emplace_back(x);
        x = pred[x];
    }
    reverse(all(way));
    for (const auto& i : way) {
        cout << i << ' ';
    }

    return 0;
}