#pragma once
#pragma GCC target("avx")

#include <bits/stdc++.h>

std::vector<std::pair<int, int>> req;
std::vector<int> order, height, tree, first;
std::vector<bool> used;
std::vector<std::vector<int>> graph;

void dfs(int v, int h = 1) {
    used[v] = true;
    height[v] = h;
    order.emplace_back(v);
    for (auto& u : graph[v]) {
        if (!used[u]) {
            dfs(u, h + 1);
            order.emplace_back(v);
        }
    }
}

void build(int v, int l, int r) {
    if (l == r) {
        tree[v] = order[l];
    } else {
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        tree[v] = (height[tree[2 * v]] < height[tree[2 * v + 1]] ? tree[2 * v] : tree[2 * v + 1]);
    }
}

int get_min(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return tree[v];
    }
    int tm = (tr + tl) / 2;
    if (r <= tm) {
        return get_min(2 * v, tl, tm, l, r);
    }
    if (l > tm) {
        return get_min(2 * v + 1, tm + 1, tr, l, r);
    }
    int way_1 = get_min(2 * v, tl, tm, l, tm);
    int way_2 = get_min(2 * v + 1, tm + 1, tr, tm + 1, r);
    return (height[way_1] <= height[way_2] ? way_1 : way_2);
}

int get_lca(int v, int u) {
    int left = first[v];
    int right = first[u];
    if (left > right) {
        std::swap(left, right);
    }
    return get_min(1, 0, order.size() - 1, left, right);
}

void __init__(int n) {
    used.assign(n, false);
    order.reserve(2 * n);
    first.assign(n, -1);
    height.resize(n);
    graph.resize(n);
}

int main() {
    //std::ios_base::sync_with_stdio(false);
    //std::cin.tie(NULL), std::cout.tie(NULL);

    int n, v, u;
    std::cin >> n;
    __init__(n);
    for (int i = 0; i < n - 1; i++) {
        std::cin >> u >> v;
        u--; v--;
        graph[v].emplace_back(u);
        graph[u].emplace_back(v);
    }

    dfs(0);
    tree.assign(4 * order.size() + 1, -1);
    build(1, 0, order.size() - 1);
    for (int i = 0; i < order.size(); i++) {
        if (first[order[i]] == -1) {
            first[order[i]] = i;
        }
    }
    std::cout << "===============\n";
    while (std::cin >> v >> u) {
        v--; u--;
        std::cout << get_lca(v, u) + 1 << '\n';
    }

    return 0;
}
