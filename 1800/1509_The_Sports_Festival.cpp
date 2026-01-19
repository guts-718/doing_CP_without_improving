#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXN = 2048;

ll dp[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (ll d=1; d<n; d++) {
        for (ll l=0; l<n; l++) {
            ll r=l+d;
            if (r>=n) continue;
            dp[l][r] = arr[r]-arr[l];
            dp[l][r] += min(dp[l+1][r], dp[l][r-1]);
        }
    }
    cout << dp[0][n-1] << '\n';
}
