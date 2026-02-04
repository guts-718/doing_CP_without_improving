#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    int n, m; cin >> n >> m;
    
    vector <string> a(n);
    for (auto &x : a) cin >> x;
    
    bool sw = false;
    if (n > m){
        vector <string> b(m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                b[j] += a[i][j];
            }
        }
        
        swap(a, b);
        swap(n, m);
        sw = true;
    }
    
    assert(n <= m);
    
    // brute over pairs of rows
    
    vector<vector<int>> info(n, vector<int>(m));
    vector<vector<int>> ans(n, vector<int>(m, INF));
    
    for (int i1 = 0; i1 < n; i1++){
        // store information over multiple i2 
        // then update at the end 
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                info[i][j] = INF;
            }
        }
        for (int i2 = i1 + 1; i2 < n; i2++){
            int lst = -1;
            for (int j = 0; j < m; j++){
                bool good = (a[i1][j] == '1' && a[i2][j] == '1');
                if (good){
                    if (lst != -1){
                        int got = (j - lst + 1) * (i2 - i1 + 1);
                        // cout << "GOT " << i1 << " " << i2 << " " << lst << " " << j << " " << got << "\n";
                        
                        for (int col = lst; col <= j; col++){
                            // for rows i1...i2 and column = col, update answer? 
                            info[i2][col] = min(info[i2][col], got);
                        }
                    }
                    lst = j;
                }
            }
        }
        
        // for cell r >= i1, we should update with results of i2 >= r 
        for (int i2 = n - 2; i2 >= i1; i2--){
            for (int j = 0; j < m; j++){
                info[i2][j] = min(info[i2][j], info[i2 + 1][j]);
            }
        }
        
        for (int i2 = i1; i2 < n; i2++){
            for (int j = 0; j < m; j++){
                ans[i2][j] = min(ans[i2][j], info[i2][j]);
            }
        }
    }
    
    for (auto &x : ans){
        for (auto &y : x){
            if (y == INF){
                y = 0;
            }
        }
    }
    
    if (sw){
        for (int j = 0; j < m; j++){
            for (int i = 0; i < n; i++){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
   
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
  
}