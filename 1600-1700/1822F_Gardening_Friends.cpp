// ************* INCOMPLETE - TO BE SOLVED ***********************
#include<bits/stdc++.h>
using namespace std;
int n,k,c;
vector<int>depth;
vector<int>dp;
int ans=0;
int helper(int node,int par,vector<int>adj[],int deep){
    depth[node]=deep;
    int m1=-1,m2=-1
    for(auto x:adj[node]){
        int cur=helper(x,node,adj,deep+1);
        if(cur>=m1){
            m2=m1;
            m1=cur;
            
        }else if(cur>m2)m2=cur;
    }
  //  ans=max(ans,k*m1);
    dp[node]={k*m1,m2*k};
    dp1[node]=m1;
    return m1+1;
}

int help1(int node,int par,vector<int>adj[]){
     
    int m1=dp[par].first,m2=dp[par].second;
    
}
int main(){
    int t;
    cin>>t;
    cin>>n>>k>>c;
    vector<int>adj[n];
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        depth.assign(n,0);
        dp.assign(n,0);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

}