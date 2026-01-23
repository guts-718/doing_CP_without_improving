#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        map<int, vector<int>> mp;
        sort(a.begin(), a.end());

        map<int, int> m;
        for (auto x : a) {
            m[x]++;
        }
        for (auto &[x, fr] : m) {
            fr %= 2;
        }

        int cnt = 0;
        for (auto [x, v] : m) {
            if (v) {
                mp[x % k].push_back(x);
                cnt++;
            }
        }

        int f = 0;
        for (auto [x, v] : mp) {
            if (v.size() % 2 == 1) {
                f++;
            }
        }

        if ((cnt % 2 == 0 && f > 0) || (cnt % 2 == 1 && f > 1)) {
            cout << -1 << endl;
        } else {
            int ans = 0;

            for (auto [x, v] : mp) {
                int nn = v.size();
                int maxi = 0;
                if(nn%2==0){
                for (int i = 0; i + 1 < nn; i += 2) {
                    ans += (v[i + 1] - v[i]) / k;
                    maxi = max(maxi, (v[i + 1] - v[i]) / k);
                }
                
                }

                if (nn % 2 == 1) {
                    int ttt=2e15;
                    vector<int> pre_odd(nn), post_odd(nn), pre_even(nn), post_even(nn);
                    int so = 0, se = 0;

                    for (int i = 0; i < nn; i++) {
                        pre_odd[i] = so;
                        pre_even[i] = se;
                        if (i % 2 == 0) se += v[i];
                        else so += v[i];
                    }

                    so = 0; 
                    se = 0;
                    for (int i = nn - 1; i >= 0; i--) {
                        post_odd[i] = so;
                        post_even[i] = se;
                        if (i % 2 == 0) se += v[i];
                        else so += v[i];
                    }

                    for (int i = 0; i < nn; i++) {
                        ttt = min(ttt,
                                  (pre_odd[i] + post_even[i]
                                   - pre_even[i] - post_odd[i]) / k);
                    }
                    ans+=ttt;
                }
            }

            cout << ans << endl;
        }
    }
}
