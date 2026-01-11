#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = std::sqrt(1E9);

std::vector<int> isprime(N + 1, 1);
std::vector<int> primes;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::set<int> s;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (auto p : primes) {
            if (p * p > x) {
                break;
            }
            if (x % p == 0) {
                if (s.contains(p)) {
                    std::cout << "YES\n";
                    return;
                }
                s.insert(p);
                while (x % p == 0) {
                    x /= p;
                }
            }
        }
        if (x > 1) {
            if (s.contains(x)) {
                std::cout << "YES\n";
                return;
            }
            s.insert(x);
        }
    }
    
    std::cout << "NO\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    for (int i = 2; i <= N; i++) {
        if (isprime[i]) {
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > N) {
                break;
            }
            isprime[i * p] = 0;
            if (i % p == 0) {
                break;
            }
        }
    }
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}




#include <bits/stdc++.h>
using namespace std;

struct DisjointSet {
    vector<int> parent, sz;

    DisjointSet(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUpar(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findUpar(parent[x]);
    }

    void join(int a, int b) {
        a = findUpar(a);
        b = findUpar(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }

    int size(int x) {
        return sz[findUpar(x)];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        DisjointSet dsu(n * 10); // safe upper bound
        unordered_map<int, int> mp;
        int id = 0;

        for (int idx = 0; idx < n; idx++) {
            int cur = a[idx];

            if (!mp.count(cur)) mp[cur] = id++;
            else continue;

            if (cur % 2 == 0) {
                if (!mp.count(2)) mp[2] = id++;
                dsu.join(mp[a[idx]], mp[2]);
                while (cur % 2 == 0) cur /= 2;
            }

            for (int p = 3; p * p <= cur; p += 2) {
                if (cur % p == 0) {
                    if (!mp.count(p)) mp[p] = id++;
                    dsu.join(mp[a[idx]], mp[p]);
                    while (cur % p == 0) cur /= p;
                }
            }

            if (cur > 1) {
                if (!mp.count(cur)) mp[cur] = id++;
                dsu.join(mp[a[idx]], mp[cur]);
            }
        }
       unordered_map<int,int>mpp;
        bool ok = false;
        for (int i=0;i<n;i++) {
            mpp[dsu.findUpar(mp[a[i]])]++;
            if( mpp[dsu.findUpar(mp[a[i]])]>=2){
                  ok = true;
                break;
            }
           
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}