#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<long long> a(n), b(m);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        string s;
        vector<long long> D(k + 1, 0);
        cin >> s;

        sort(b.begin(), b.end());

        
        
        for (int i = 1; i <= k; i++) {
            D[i] = D[i - 1] + (s[i - 1] == 'R' ? 1 : -1);
        }

        
        vector<long long> prefMin(k + 1);
        vector<long long>prefMax(k + 1);
        prefMin[0] = D[0];
        prefMax[0] = D[0];
        for (int i = 1; i <= k; i++) {
            prefMin[i] = min(prefMin[i - 1], D[i]);
            prefMax[i] = max(prefMax[i - 1], D[i]);
        }

        vector<int> death(k + 2, 0);

        for (int i = 0; i < n; i++) {
             long long l = LLONG_MIN, r = LLONG_MAX;
            long long pos = a[i];

            auto it = lower_bound(b.begin(), b.end(), pos);

          

            if (it != b.begin()) {
                l = *(it - 1) - pos + 1;
            }
            if (it != b.end()) {
                r = *it - pos - 1;
            }

            int  hi = k, lo = 0, ans = k + 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (prefMin[mid] < l || prefMax[mid] > r) {
                   
                    hi = mid - 1;
                    ans = mid;
                } else {
                    lo = mid + 1;
                }
            }

            if (ans <= k) {
                death[ans]++;
            }
        }
        int alive = n;
        for (int i = 1; i <= k; i++) {
            alive -= death[i];
            cout << alive << " ";
        }
        cout << endl;
    }
    return 0;
}
