#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (*max_element(a.begin(), a.end()) == 0) {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";

        vector<long long> pos, neg;
        for (auto x : a) {
            if (x >= 0) pos.push_back(x);
            else neg.push_back(x);
        }

        long long prefix_sum = 0;
        vector<long long> ans;

        for (int i = 0; i < n; i++) {
            if (prefix_sum <= 0) {
                ans.push_back(pos.back());
                pos.pop_back();
            } else {
                ans.push_back(neg.back());
                neg.pop_back();
            }
            prefix_sum += ans.back();
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i + 1 < n ? ' ' : '\n');
        }
    }

    return 0;
}
