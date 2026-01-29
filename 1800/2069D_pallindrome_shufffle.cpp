#include <bits/stdc++.h>
using namespace std;

bool check(const string &s, int mid) {
    int n = (int)s.size();

    // Check palindrome for the middle part
    for (int i = mid; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }

    multiset<char> leftChars;

    // Store first mid characters
    for (int i = 0; i < mid; i++) {
        leftChars.insert(s[i]);
    }

    // Match them with last mid characters
    for (int i = n - 1; i >= mid && i >= n - mid; i--) {
        auto it = leftChars.find(s[i]);
        if (it == leftChars.end()) {
            return false;
        }
        leftChars.erase(it);
    }

    return true;
}

void solve() {
    string s;
    cin >> s;
    int n = (int)s.size();

    // Remove matching prefix and suffix
    int p = 0;
    while (p < n && s[p] == s[n - 1 - p]) {
        p++;
    }

    if (p == n) {
        cout << 0 << '\n';
        return;
    }

    string mid = s.substr(p, n - 2 * p);
    string rev = mid;
    reverse(rev.begin(), rev.end());

    int low = 0, high = (int)mid.size();

    while (low < high) {
        int m = (low + high) / 2;
        if (check(mid, m) || check(rev, m)) {
            high = m;
        } else {
            low = m + 1;
        }
    }

    cout << low << '\n';
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






#include <bits/stdc++.h>
 
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int i = 0;
    while (i < n / 2 && s[i] == s[n - i - 1]) ++i;
    n -= 2 * i;
    s = s.substr(i, n);
    int ans = n;
    for (int z = 0; z < 2; ++z) {
      int l = 0, r = n;
      while (l <= r) {
        int m = (l + r) / 2;
        vector<int> cnt(26);
        for (int i = 0; i < m; ++i)
          cnt[s[i] - 'a']++;
        bool ok = true;
        for (int i = 0; i < min(n / 2, n - m); ++i) {
          char c = s[n - i - 1];
          if (i < m) {
            ok &= cnt[c - 'a'] > 0;
            cnt[c - 'a']--;
          } else {
            ok &= (c == s[i]);
          }
        }
        for (auto x : cnt)
          ok &= (x % 2 == 0);
        if (ok) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      ans = min(ans, r + 1); 
      reverse(s.begin(), s.end());
    }
    cout << ans << '\n';
  }
}