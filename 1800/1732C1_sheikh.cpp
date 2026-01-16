#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        // Prefix sum and prefix xor
        vector<int> prefSum = a, prefXor = a;
        for (int i = 1; i < n; i++) {
            prefSum[i] += prefSum[i - 1];
            prefXor[i] ^= prefXor[i - 1];
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; r--;  

            int totalSum = prefSum[r] - (l ? prefSum[l - 1] : 0);
            int totalXor = prefXor[r] ^ (l ? prefXor[l - 1] : 0);
            int target = totalSum - totalXor;

            int ans = r - l + 1;
            pair<int,int>sol={l,r};

            for (int i = l; i <= r; i++) {
                int curSum = prefSum[i] - (l ? prefSum[l - 1] : 0);
                int curXor = prefXor[i] ^ (l ? prefXor[l - 1] : 0);

                if (curSum - curXor != target) continue;

                // Try shrinking from the left
                int L = l, R = i;
                int RR=R;
                while (L <= R) {
                    int mid = (L + R) / 2;

                    int s = prefSum[RR] - (mid ? prefSum[mid - 1] : 0);
                    int x = prefXor[RR] ^ (mid ? prefXor[mid - 1] : 0);

                    if (s - x == target) {
                       // ans = min(ans, R - mid + 1);
                        if(ans>RR-mid+1){
                            ans=RR-mid+1,
                            sol={mid,RR};
                        }
                        L = mid + 1;
                    } else {
                        R = mid - 1;
                        
                       
                    }
                }
            }

            cout <<sol.first+1<<" "<<sol.second+1<< '\n';
        }
    }

    return 0;
}
