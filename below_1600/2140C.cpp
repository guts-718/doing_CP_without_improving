#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const ll INF = (ll)2e18;

void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    ll base = 0;
    ll mn = INF;          // stores min(2*a[i] + i) for even i
    ll mxOdd = -INF;      // stores max(2*a[i] - i) for odd i
    ll best = 0;

    for (ll i = 0; i < n; i++) {
        if (i & 1) {
            base -= a[i];
            best = max(best, 2 * a[i] + i - mn);
            mxOdd = max(mxOdd, 2 * a[i] - i);
        } else {
            base += a[i];
            mn = min(mn, 2 * a[i] + i);
            best = max(best, mxOdd - (2 * a[i] - i));
        }
    }

    ll tail = (n & 1) ? (n - 1) : (n - 2);
    best = max(best, tail);

    cout << base + best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}