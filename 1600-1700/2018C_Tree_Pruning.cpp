#include <bits/stdc++.h>
using namespace std;

vector<int> dp, parent;
int mx_ht;

int dfs(int node, int par, vector<int> adj[], int ht,
        map<int, vector<int>>& mp) {
    int ans = 0;
    mx_ht = max(mx_ht, ht);
    parent[node] = par;

    if (adj[node].size() == 1 && par != -1)
        mp[ht].push_back(node);

    for (auto x : adj[node]) {
        if (x == par) continue;
        ans += dfs(x, node, adj, ht + 1, mp);
    }

    dp[node] = ans;
    return ans + 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        mx_ht = 0;

        vector<int> adj[n];
        dp.assign(n, 0);
        parent.assign(n, -1);
        vector<int>sz(n+2);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            sz[u]++;
            sz[v]++;
        }
       
        map<int, vector<int>> mp;
        dfs(0, -1, adj, 1, mp);

        vector<int> vis(n, 0);
        vector<int> dp1(mx_ht + 2, 0);

        int cnt = 0;
        for (int i = 1; i <= mx_ht; i++) {
            for (auto v : mp[i]) {
                int node = v;
                while (node != -1 && !vis[node] && sz[node]==1) {
                    vis[node] = 1;
                    cnt++;
                    node = parent[node];
                    if(node!=-1)sz[node]--;
                    if(node==0)break;
                }
            }
            //cnt--;
            dp1[i] = cnt;
        }

        fill(vis.begin(), vis.end(), 0);

        queue<int> q;
        q.push(0);
        vis[0] = 1;

        int depth = 1;
        int answer = INT_MAX;

        while (!q.empty()) {
            int sz = q.size();
            int cur = 0;

            while (sz--) {
                int x = q.front();
                q.pop();
                cur += dp[x];

                for (auto y : adj[x]) {
                    if (!vis[y]) {
                        vis[y] = 1;
                        q.push(y);
                    }
                }
            }

            answer = min(answer, max(0,cur + dp1[depth-1]));
            depth++;
        }

        cout << answer << endl;
    }
}
