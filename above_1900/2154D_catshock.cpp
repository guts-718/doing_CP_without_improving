#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<int> del, dep(n);
    auto dfs = [&](this auto &&self, int x, int p) -> void {
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            dep[y] = dep[x] + 1;
            self(y, x);
        }
        if (x != n - 1) {
            del.push_back(x);
        }
    };
    dfs(n - 1, -1);
    
    int lst = dep[0] % 2;
    std::vector<int> ans;
    for (auto x : del) {
        ans.push_back(0);
        lst ^= 1;
        if (lst == dep[x] % 2) {
            ans.push_back(0);
            lst ^= 1;
        }
        ans.push_back(x + 1);
    }
    
    std::cout << ans.size() << "\n";
    for (auto x : ans) {
        if (x) {
            std::cout << 2 << " " << x << "\n";
        } else {
            std::cout << 1 << "\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
