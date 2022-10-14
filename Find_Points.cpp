#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbeging(), a.rend()

const int MAXN = 1e3 + 1;
vector<int> graph[MAXN];
bool used[MAXN];
int timer = 0, deep[MAXN], dp[MAXN];
set<int> points;
 
void find_points(int v, int pred) {
	used[v] = true;
    deep[v] = dp[v] = timer++;
    int child = 0;
    for (auto& i : graph[v]) {
        if (i == pred) {
            continue;
        }
        if (used[i]) {
            dp[v] = min(dp[v], deep[i]);
        } else {
            find_points(i, v);
            dp[v] = min(dp[i], dp[v]);
            if (dp[i] > deep[v] && pred != -1) {
                points.insert(v);
            }
            child++;
        }
    }
    if (pred == -1 && child > 1) {
        points.insert(v);
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
            find_points(i, -1);
        }
    }

    for (const auto& i : points) {
        cout << i << '\n';
    }

    return 0;
}