/*
Let's try to estimate the number of possible integers that can be obtained using these operations to see if we can consider 
all possible options. The key observation is that each integer we obtain will have the form x⋅(2^a)⋅(3^b)⋅(5^c)⋅(7^d), 
since only one-digit primes can be added to the factorization. Since we consider only numbers less than 1019, a is not greater 
than 63, b is not greater than 39, c is not greater than 27, and d is not greater than 22, and the number of reachable integers 
is about 1.5 million (note that this is a very generous bound since not all combinations of (a,b,c,d) yield an integer less than 
1019, and not all such integers can be reached with the operations).

This allows us to use BFS or dynamic programming to calculate the answer.*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (*max_element(a.begin(), a.end()) == 0) {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";

        vector<long long> pos, neg;
        for (auto x : a) {
            if (x >= 0) pos.push_back(x);
            else neg.push_back(x);
        }

        long long prefix_sum = 0;
        vector<long long> ans;

        for (int i = 0; i < n; i++) {
            if (prefix_sum <= 0) {
                ans.push_back(pos.back());
                pos.pop_back();
            } else {
                ans.push_back(neg.back());
                neg.pop_back();
            }
            prefix_sum += ans.back();
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i + 1 < n ? ' ' : '\n');
        }
    }

    return 0;
}
