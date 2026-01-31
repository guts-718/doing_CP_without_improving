#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int N, C;
        cin >> N >> C;
        C--; 

        vector<string> S(N);
        for(int i=0;i<N;i++) cin >> S[i];

        vector<vector<int>> walls(N);
        for(int r=0;r<N;r++){
            for(int c=0;c<N;c++){
                if(S[r][c]=='#')
                    walls[c].push_back(r);
            }
        }
        queue<pair<int,int>> q;
        vector<char> top(N,'0');
        q.push({N-1, C});
       
        vector<vector<int>> vis(N, vector<int>(N,0));
       
       
        vis[N-1][C] = 1;

        while(!q.empty()){
            auto [r,c] = q.front(); q.pop();

            if(r == 0){
                top[c] = '1';
                continue;
            }

            for(int dc=-1; dc<=1; dc++){
                int nr = r - 1;
                int nc = c + dc;
                
                if(vis[nr][nc]) continue;
                if(nc<0 || nc>=N) continue;

                if(S[nr][nc]=='.'){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
                else{ 
                    if(!walls[nc].empty() && walls[nc].back()==nr){
                        q.push({nr,nc});
                        walls[nc].pop_back(); 
                        vis[nr][nc]=1;
                    }
                }
            }
        }

        for(auto x:top)cout<<x<<"";
        cout<<endl;
        
    }
    return 0;
}
