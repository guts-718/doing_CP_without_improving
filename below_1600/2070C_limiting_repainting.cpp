#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;
vector<int> a;

bool check(int d) {
    char last = 'R';
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > d) {
            if (s[i] == 'B' && last != 'B') {
                cnt++;
            }
            last = s[i];
        }
    }
    return cnt <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin >> s;

        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int left = 0, right = 1000000000;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << result << '\n';
    }

    return 0;
}
