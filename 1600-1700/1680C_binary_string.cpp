#include <bits/stdc++.h>
using namespace std;

static const char NL = '\n';

string s;
int n;
vector<int> zeroPos;

bool canDo(int k) {
    if ((int)zeroPos.size() <= k + 2) return true;

    for (int i = 0; i + k + 1 < (int)zeroPos.size(); i++) {
        int L = zeroPos[i] + 1;
        int R = zeroPos[i + k + 1] - 1;

        int onesLeft = 0;
        if (L <= R) {
            int len = R - L + 1;
            onesLeft = len - k;
        }

        int totalOnes = n - ((int)zeroPos.size() - 2);
        int onesRemoved = totalOnes - onesLeft;

        if (onesRemoved <= k) return true;
    }
    return false;
}

void solve() {
    cin >> s;
    n = (int)s.size();

    zeroPos.clear();
    zeroPos.push_back(-1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') zeroPos.push_back(i);
    }
    zeroPos.push_back(n);

    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (canDo(mid)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << NL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}