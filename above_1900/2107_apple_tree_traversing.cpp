#include <bits/stdc++.h>
using namespace std;

static const int N = 150005;

vector<int> g[N];
bool dead[N];
int dep[N], par[N];

vector<pair<int,int>> buf;
vector<array<int,3>> ans;

void dfs(int u, int p) {
    dep[u] = dep[p] + 1;
    par[u] = p;
    buf.push_back({dep[u], u});
    for (int v : g[u])
        if (v != p && !dead[v])
            dfs(v, u);
}

void solve_diam(int s) {
    buf.clear();
    dfs(s, 0);
    int u = max_element(buf.begin(), buf.end())->second;

    buf.clear();
    dfs(u, 0);
    int v = max_element(buf.begin(), buf.end())->second;

    buf.clear();
    dfs(v, 0);
    int w = max_element(buf.begin(), buf.end())->second;

    int x = max({u, v, w});

    buf.clear();
    dfs(x, 0);
    auto [d, y] = *max_element(buf.begin(), buf.end());

    vector<int> path;
    for (int cur = y; cur; cur = par[cur])
        path.push_back(cur);
    reverse(path.begin(), path.end());

    for (int z : path) dead[z] = true;

    ans.push_back({d, x, y});

    for (int z : path)
        for (int nx : g[z])
            if (!dead[nx])
                solve_diam(nx);
}

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        g[i].clear();
        dead[i] = false;
    }

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ans.clear();
    solve_diam(1);

    sort(ans.begin(), ans.end(), greater<>());
    for (auto &a : ans)
        cout << a[0] << ' ' << a[1] << ' ' << a[2] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
