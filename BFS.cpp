#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbeging(), a.rend()

const int MAXN = 1e6 + 1;
vector<int> graph[MAXN];
int pred[MAXN];
bool used[MAXN];

inline void BFS(int v) {
    queue <int> q;
    for (int i = 0; i < MAXN; i++) {
        pred[i] = -1;
    }
    q.push(v);
    used[0] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for (const auto& i : graph[x]) {
            if (!used[i]) {
                q.push(i);
                used[i] = true;
                pred[i] = x;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        a--; b--;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    cin >> u >> v;
    u--; v--;
    BFS(u);
    int st = v;
    vector<int> way;
    way.emplace_back(st);
    while (pred[st] != -1 && st != u) {
        st = pred[st];
        way.emplace_back(st);
    }
    reverse(all(way));
    cout << len(way) - 1 << '\n';
    for (const auto& i : way) {cout << i << ' ';}

    return 0;
}