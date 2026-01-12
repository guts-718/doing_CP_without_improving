#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        int m = n - 1;
        for (int i = 0; i < n; i++) cin >> p[i];

        
        vector<int> diff(n - 1);
        vector<int> L(m), R(m);
        for (int i = 0; i + 1 < n; i++) {
            diff[i] = abs(p[i] - p[i + 1]);
        }

        
       
        stack<int> st;

        for (int i = m - 1; i >= 0; i--) {
            while (!st.empty() && diff[st.top()] > diff[i])
                st.pop();
            R[i] = st.empty() ? m : st.top();
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        
        for (int i = 0; i < m; i++) {
            while (!st.empty() && diff[st.top()] >= diff[i])
                st.pop();
            L[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        

       


        vector<ll> ans(n + 2, 0);

        for (int i = 0; i < m; i++) {
            ll cnt = 1LL *(R[i] - i)*(i - L[i]);
            ans[1] += cnt;
            ans[diff[i] + 1] -= cnt;
        }

        for (int k = 1; k <= n - 1; k++) {
            ans[k] += ans[k - 1];
            cout << ans[k] <<" ";
            
        }
        cout<<endl;
    }
    return 0;
}
