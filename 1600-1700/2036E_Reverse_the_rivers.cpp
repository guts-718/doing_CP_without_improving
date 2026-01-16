#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, Q;
    cin >> n >> k >> Q;

    vector<vector<int>> v(k, vector<int>(n));

    // input column-wise
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> v[j][i];
        }
    }

    // prefix OR
    for (int i = 0; i < k; i++) {
        for (int j = 1; j < n; j++) {
            v[i][j] |= v[i][j - 1];
        }
    }

    while (Q--) {
        int m;
        cin >> m;

        vector<int> lefts, rights; 

        while (m--) {
            int a = 0, b = 0;
            bool rhs = false;
            char op = '0';
            cin>>a;
            cin>>op;
            cin>>b;
            a--; 

            if (op == '>') {
                int idx = upper_bound(v[a].begin(), v[a].end(), b) - v[a].begin();
                lefts.push_back(idx);
            } else { // '<'
                int idx = lower_bound(v[a].begin(), v[a].end(), b) - v[a].begin();
                idx--;
                rights.push_back(idx);
            }
        }

        int L = 0, R = n - 1;
        for (int x : lefts) L = max(L, x);
        for (int x : rights) R = min(R, x);

        if (L > R) cout << -1 << "\n";
        else cout << L+1 << "\n";
    }

    return 0;
}
