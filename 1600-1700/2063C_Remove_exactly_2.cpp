// dont always think of roots -- we dont always need to consider them.....
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j : a[i]) {
			ans = max(ans, (int)(a[i].size() + a[j].size()) - 2);
		}
	}
	multiset<int> S;
	for (int i = 0; i < n; ++i) {
		S.insert(a[i].size());
	}
	for (int i = 0; i < n; ++i) {
		S.erase(S.find(a[i].size()));
		for (int j : a[i]) {
			S.erase(S.find(a[j].size()));
		}
		if (!S.empty()) {
			ans = max(ans, (int)a[i].size() + *S.rbegin() - 1);
		}
		S.insert(a[i].size());
		for (int j : a[i]) {
			S.insert(a[j].size());
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}