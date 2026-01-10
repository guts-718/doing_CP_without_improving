// very important question for 4-pointer n^2 solutions.....
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    pbds;

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        int n,ans=0; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        pbds st;
        for (int i = n - 1; i >= 3; i--) st.insert(arr[i]);
        for (int i = 2; i <= n - 2; i++)
        {
            st.erase(arr[i]);
            int tup = 0; bool ok = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[j] < arr[i])
                {
                    if (ok) ans += tup;
                    tup += st.order_of_key(arr[j]);
                }
                else
                {
                    tup += st.order_of_key(arr[j]);
                }
                ok=1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}