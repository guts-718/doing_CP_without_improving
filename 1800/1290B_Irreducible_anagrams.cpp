#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    s = " " + s;
    int n = s.length() - 1;

    vector<vector<int>> sum(n + 1, vector<int>(26, 0));

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1];
        sum[i][s[i] - 'a']++;
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            cnt += (sum[r][i] - sum[l - 1][i] > 0);
        }

        if (l == r || cnt >= 3 || s[l] != s[r]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
