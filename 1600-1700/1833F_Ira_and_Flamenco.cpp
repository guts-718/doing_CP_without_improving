#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;
static const int MAXN = 200200;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) {
    return (long long)a * b % MOD;
}

int n, m;
int a[MAXN], b[MAXN], cnt[MAXN];
int k;

void build() {
    sort(a, a + n);
    memcpy(b, a, sizeof(int) * n);
    k = unique(a, a + n) - a;
    for (int i = 0; i < k; i++) {
        cnt[i] = upper_bound(b, b + n, a[i]) - lower_bound(b, b + n, a[i]);
    }
}

void push(stack<pair<int,int>> &s, int x) {
    int p = s.empty() ? 1 : s.top().second;
    s.push({x, mul(x, p)});
}

int solve() {
    if (k < m) return 0;

    stack<pair<int,int>> s1, s2;
    for (int i = 0; i < m; i++) {
        push(s1, cnt[i]);
    }

    int ans = 0;

    for (int r = m; r <= k; r++) {
        if (a[r - 1] - a[r - m] == m - 1) {
            int p1 = s1.empty() ? 1 : s1.top().second;
            int p2 = s2.empty() ? 1 : s2.top().second;
            ans = add(ans, mul(p1, p2));
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                push(s2, s1.top().first);
                s1.pop();
            }
        }
        s2.pop();

        if (r < k) {
            push(s1, cnt[r]);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        build();
        cout << solve() << "\n";
    }
    return 0;
}




// 2nd - inverse mod method

#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1'000'000'007;
static const int MAXN = 200200;

int n, m;
int a[MAXN], tmp[MAXN];
int freq[MAXN];
int k;


long long modPow(long long a, long long e) {
    long long res = 1;
    while (e) {
        if (e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

long long modInv(long long a) {
    return modPow(a, MOD - 2);   
}



void build() {
    sort(a, a + n);
    memcpy(tmp, a, sizeof(int) * n);

    k = unique(a, a + n) - a;

    for (int i = 0; i < k; i++) {
        freq[i] =
            upper_bound(tmp, tmp + n, a[i]) -
            lower_bound(tmp, tmp + n, a[i]);
    }
}


int solve() {
    if (k < m) return 0;

    vector<long long> pref(k + 1, 1);
    for (int i = 0; i < k; i++) {
        pref[i + 1] = pref[i] * freq[i] % MOD;
    }

    int ans = 0;

    for (int r = m; r <= k; r++) {
        int l = r - m;

        if (a[r - 1] - a[l] == m - 1) {
            long long windowProduct =
                pref[r] * modInv(pref[l]) % MOD;
            ans = (ans + windowProduct) % MOD;
        }
    }

    return ans;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        build();
        cout << solve() << "\n";
    }
    return 0;
}
