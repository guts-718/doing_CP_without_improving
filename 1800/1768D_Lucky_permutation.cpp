#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;  // convert to 0-based indexing
    }

    int component_id = 1;
    int answer = 0;
    vector<int> component(n, 0);

    for (int i = 0; i < n; i++) {
        if (component[i] != 0) {
            continue;
        }

        int v = i;
        while (component[v] == 0) {
            component[v] = component_id;
            v = p[v];
            answer++;
        }

        component_id++;
        answer--;
    }

    for (int i = 0; i < n - 1; i++) {
        if (component[i] == component[i + 1]) {
            cout << answer - 1 << '\n';
            return;
        }
    }

    cout << answer + 1 << '\n';
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
