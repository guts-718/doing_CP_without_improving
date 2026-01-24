#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, m;
    cin >> n >> m;

    vector<long long> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<long long> sa(1, 0), sb(1, 0);

    // Build prefix sums of pair differences for a
    for (int l = 0, r = n - 1; l < r; l++, r--) {
        sa.push_back(a[r] - a[l]);
    }

    // Build prefix sums of pair differences for b
    for (int l = 0, r = m - 1; l < r; l++, r--) {
        sb.push_back(b[r] - b[l]);
    }

    // Prefix sum accumulation
    for (int i = 1; i < (int)sa.size(); i++) {
        sa[i] += sa[i - 1];
    }
    for (int i = 1; i < (int)sb.size(); i++) {
        sb[i] += sb[i - 1];
    }

    vector<long long> answer;

    // Try all k
    for (long long k = 1; ; k++) {
        long long low = max(0LL, 2 * k - m);
        long long high = min(k, n - k);
        if (low > high) break;

        // Ternary-like optimization on discrete range
        while (high - low >= 3) {
            long long m1 = (2 * low + high) / 3;
            long long m2 = (low + 2 * high) / 3;

            long long v1 = sa[m1] + sb[k - m1];
            long long v2 = sa[m2] + sb[k - m2];

            if (v1 < v2)
                low = m1;
            else
                high = m2;
        }

        long long best = 0;
        for (long long i = low; i <= high; i++) {
            best = max(best, sa[i] + sb[k - i]);
        }
        answer.push_back(best);
    }

    cout << answer.size() << '\n';
    for (auto x : answer) cout << x << ' ';
    cout << '\n';
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
