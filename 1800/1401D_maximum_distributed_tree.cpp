#include <bits/stdc++.h>
using namespace std;

static constexpr int MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<long long> contrib;
        vector<int> sz(n);

        function<void(int, int)> dfs = [&](int u, int parent) {
            sz[u] = 1;
            for (int v : adj[u]) {
                if (v == parent) continue;
                dfs(v, u);
                sz[u] += sz[v];
                contrib.push_back(1LL * sz[v] * (n - sz[v]));
            }
        };

        dfs(0, -1);
        sort(contrib.begin(), contrib.end());

        int m;
        cin >> m;
        vector<int> p(m);
        for (int &x : p) cin >> x;
        sort(p.begin(), p.end());

        long long ans = 0;

        if (m <= n - 1) {
            int shift = (n - 1) - m;
            for (int i = 0; i < n - 1; ++i) {
                if (i < shift) {
                    ans = (ans + contrib[i]) % MOD;
                } else {
                    ans = (ans + contrib[i] % MOD * p[i - shift]) % MOD;
                }
            }
        } else {
            for (int i = 0; i < n - 2; ++i) {
                ans = (ans + contrib[i] % MOD * p[i]) % MOD;
            }

            long long prod = 1;
            for (int i = n - 2; i < m; ++i) {
                prod = prod * p[i] % MOD;
            }

            ans = (ans + contrib[n - 2] % MOD * prod) % MOD;
        }

        cout << ans << '\n';
    }

    return 0;
}
