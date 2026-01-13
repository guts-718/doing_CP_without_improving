#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = -1;
    int ans = 0;
    for (int i = 1, lf = 0; i <= n; i++) {
        if (a[i] == 0) {
            if (lf) {
                lf = 0;
                a[i] = -1;
            } else {
                ans++;
            }
        } else if (a[i] == 1) {
            if (a[i - 1] == -1) {
                lf = 1;
                ans++;
            }
        } else {
            if (a[i - 1] == -1) {
                ans++;
            }
            lf = 1;
        }
    }
    cout << ans;
}
