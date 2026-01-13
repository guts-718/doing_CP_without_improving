#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int MOD = 1000000007;

int n;
vector<int> p;
string s;

void solve() {
    cin >> n;
    cin >> s;

    p.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    // make string 1-indexed
    s = " " + s;

    vector<int> visited(n + 1, 0);
    ll answer = 1;

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;

        int cur = i;
        string cycle;
        cycle.push_back(s[i]);
        visited[i] = 1;

        while (p[cur] != i) {
            cur = p[cur];
            visited[cur] = 1;
            cycle.push_back(s[cur]);
        }

        string rotated = cycle;
        int len = cycle.size();

        for (int shift = 1; shift <= len; shift++) {
            rotate(rotated.begin(), rotated.begin() + 1, rotated.end());
            if (rotated == cycle) {
                ll g = gcd(answer, (ll)shift);
                answer = (answer / g) * shift;
                break;
            }
        }
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
