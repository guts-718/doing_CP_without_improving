#include <bits/stdc++.h>
using namespace std;

int DIG = 10;

struct Parent {
    int prev_rem;
    char prev_last;
    char digit;
};

int main(){
   
    int N;
    cin >> N;

    vector<vector<char>> vis(N, vector<char>(DIG, 0));
    vector<vector<Parent>> par(N, vector<Parent>(DIG));

    queue<pair<int,int>> q;

    for(int d=1; d<=9; d++){
        int r = d % N;
        if(!vis[r][d]){
            vis[r][d]=1;
            par[r][d] = {-1, -1, (char)d};
            q.push({r,d});
        }
    }

    int end_last=-1;
    int end_rem=-1;
   
    while(!q.empty()){
        auto [rem,last] = q.front(); q.pop();

        if(rem==0){
            end_last=last;
            end_rem=rem;
            break;
        }

        for(int d=last; d<=9; d++){
            int nr = ( (long long)rem*10 + d ) % N;
            if(!vis[nr][d]){
               
                q.push({nr,d});
                par[nr][d] = {rem, (char)last, (char)d};
                vis[nr][d]=1;
                
            }
        }
    }

    if(end_last==-1){
        cout << -1 << endl;
        return 0;
    }

   
   
    int r=end_rem;
    int l=end_last;
    string ans;
    while(1){
        Parent p = par[r][l];
        ans.push_back(char('0'+p.digit));
        if(p.prev_rem==-1) break;
       
        int pr = p.prev_rem;
        int pl = p.prev_last;
        r=pr; l=pl;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
