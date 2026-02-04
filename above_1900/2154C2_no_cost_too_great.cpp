#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int MAXV = 200000 + 1;

vector<int> minPrime, primes;
bitset<MAXV + 1> usedPrime;

/* Linear Sieve */
void buildSieve(int n) {
    minPrime.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (i * p > n) break;
            minPrime[i * p] = p;
            if (p == minPrime[i]) break;
        }
    }
}

/* Extract unique prime factors */
vector<int> uniquePrimes(int x) {
    vector<int> res;
    while (x > 1) {
        int p = minPrime[x];
        res.push_back(p);
        while (x % p == 0) x /= p;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    vector<int> usedList;
    bool conflict = false;

    /* Check duplicate prime usage */
    for (int i = 0; i < n && !conflict; ++i) {
        for (int p : uniquePrimes(a[i])) {
            if (usedPrime[p]) {
                conflict = true;
                break;
            }
            usedPrime[p] = true;
            usedList.push_back(p);
        }
    }

    if (conflict) {
        for (int p : usedList) usedPrime[p] = false;
        cout << 0 << "\n";
        return;
    }

    /* Find two smallest b's */
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    nth_element(idx.begin(), idx.begin() + 1, idx.end(),
                [&](int i, int j) { return b[i] < b[j]; });

    int best = b[idx[0]] + b[idx[1]];

    /* If any a[i] shares prime with previous */
    for (int i = 0; i < n; ++i) {
        for (int p : uniquePrimes(a[i] + 1)) {
            if (usedPrime[p]) {
                best = min(best, b[i]);
                break;
            }
        }
    }

    /* Try adjusting smallest-cost element */
    int id = idx[0];
    for (int p : usedList) {
        if (a[id] % p == 0) continue;
        int rem = a[id] % p;
        best = min<i64>(best, (i64)(p - rem) * b[id]);
    }

    cout << best << "\n";

    for (int p : usedList) usedPrime[p] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    buildSieve(MAXV);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
