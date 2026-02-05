#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;

vector<long long> ps;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end(), greater<>());

    vector<long long> pre(n+1, 0);
    for (int i = 0; i < n; i++)
        pre[i+1] = pre[i] + a[i];

    for (int i = n; i >= 0; i--) {
        if (pre[i] >= ps[i]) {
            cout << n - i << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> isp(N+1, true);
    vector<int> p;

    for (int i = 2; i <= N && (int)p.size() < 400000; i++) {
        if (isp[i]) {
            p.push_back(i);
            for (long long j = 1LL * i * 2; j <= N; j += i)
                isp[j] = false;
        }
    }

    ps.resize(p.size() + 1, 0);
    for (int i = 0; i < (int)p.size(); i++)
        ps[i+1] = ps[i] + p[i];

    int t;
    cin >> t;
    while (t--) solve();
}