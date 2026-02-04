#include <bits/stdc++.h>
using namespace std;

// Query helper (interactive style)
int query(const vector<int>& idx) {
    cout << "? " << idx.size();
    for (int x : idx) cout << " " << x;
    cout << endl;
    cout.flush();

    int res;
    cin >> res;
    if (res == -1) exit(0); // exit if invalid
    return res;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int len = 2 * n;

        vector<int> a(len + 1, -1);
        vector<int> known(len + 1, 0);
        vector<int> current;

        // ---------- Forward Pass 1: find later occurrences ----------
        current.push_back(1);
        for (int i = 2; i <= len; i++) {
            current.push_back(i);
            int res = query(current);

            if (res != 0) {
                a[i] = res;       // found later occurrence
                known[i] = 1;
            }

            // keep only unknown indices for next query
            vector<int> nxt;
            for (int x : current)
                if (!known[x]) nxt.push_back(x);
            current.swap(nxt);
        }

        // ---------- Forward Pass 2: find earlier occurrences ----------
        known.assign(len + 1, 0);
        for (int i = 1; i <= len; i++) {
            if (a[i] != -1) continue; // already known

            vector<int> idx;
            idx.push_back(i);

            // include all later known positions
            for (int j = i + 1; j <= len; j++)
                if (a[j] != -1) idx.push_back(j);

            int res = query(idx);
            if (res != 0) a[i] = res;
        }

        // ---------- Output Final Sequence ----------
        cout << "! ";
        for (int i = 1; i <= len; i++)
            cout << a[i] << (i == len ? '\n' : ' ');
        cout.flush();
    }

    return 0;
}