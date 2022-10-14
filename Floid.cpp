#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbeging(), a.rend()

const int MAXN = 1e2 + 1, INF = 1e6;
int graph[MAXN][MAXN];
int pred[MAXN][MAXN];
int n, m, v, u;

void floid() {
    for (int t = 1; t <= n; t++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][j] > graph[i][t] + graph[t][j]) {
                    graph[i][j] = graph[i][t] + graph[t][j];
                    pred[i][j] = t;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        graph[i][i] = INF;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m >> v >> u;
    v--; u--;
    for (int i = 0; i < MAXN; i++) {for (int j = 0; j < MAXN; j++) {graph[i][j] = INF; pred[i][j] = INF;}}
    for (int i = 0; i < m; i++) {
        int a, b, c;
        a--; b--;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    floid();
    cout << graph[v][u] << '\n';

    return 0;
}