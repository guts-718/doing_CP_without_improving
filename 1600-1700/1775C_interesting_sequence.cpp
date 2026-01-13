// 2^i -> 0s and then 2^i -> 1s for every bit .... in this problem only needed was the next time this perticular bit would be 0...

#include <bits/stdc++.h>
using namespace std;

int main() { 
    int t;
    cin >> t;

    while (t--) {
        long long n, x;
        cin >> n >> x;

        if ((n & x) != x) {
            cout << -1 << '\n';
            continue;
        }
        
        if(n==x){
            cout<<x<<endl;
            continue;
        }

        vector<long long> a, b;
        bool bad = false;

        for (int i = 0; i < 63; i++) {
            long long bit = 1LL << i;

            bool p = (n & bit);
            bool q = (x & bit);

            if (!p && !q) continue;

            if (p && q) {
                long long op = ((n / bit) + 1) * bit - 1;
                a.push_back(op);
            }

            if (!p && q) {
                bad = true;
                break;
            }

            if (p && !q) {
                long long op = ((n / bit) + 1) * bit;
                b.push_back(op);
            }
        }

        if (bad) {
            cout << -1 << '\n';
            continue;
        }

        // if (a.empty() || b.empty()) {
        //     cout << -1 << '\n';
        //     continue;
        // }

        long long mini = 6e18,maxi=-6e18,ans=6e18;
        for(auto x:a)mini=min(mini,x);
        for(auto x:b)maxi=max(maxi,x);
        if(maxi>=0){
            if(maxi>mini){
               bad=true;
            }
            else ans=min({ans,maxi,mini});
        }else ans=min({ans,mini});
        if(bad){
            cout<<-1<<endl;
            continue;
        }
        if(ans>=6e18){
            cout<<-1<<endl;
        }else cout<<ans<<endl;
       

      //  cout << mini << " " << maxi << '\n';
    }

    return 0;
}
