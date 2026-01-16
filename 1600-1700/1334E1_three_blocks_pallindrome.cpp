#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        // prefix count
        static int cnt[32][200001];
        for (int v = 1; v <= 30; v++) {
            cnt[v][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int v = 1; v <= 30; v++) {
                cnt[v][i] = cnt[v][i - 1];
            }
            cnt[a[i]][i]++;
        }

       
        vector<vector<int>> pos(32);
        for (int i = 1; i <= n; i++) {
            pos[a[i]].push_back(i);
        }

        int ans = 1;

        // try each outer value a
        for (int val = 1; val < 30; val++) {
            int sz = pos[val].size();
            if (sz == 0) continue;

            // try x = number of val taken from both sides
            for (int x = 1; x * 2 <= sz; x++) {
                int L = pos[val][x - 1];
                int R = pos[val][sz - x];

                int best_mid = 0;
                for (int b = 1; b < 30; b++) {
                    best_mid = max(best_mid, cnt[b][R - 1] - cnt[b][L]);
                }

                ans = max(ans, 2 * x + best_mid);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
