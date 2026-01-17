#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<pair<int,int>>v;
	    set<int>s;
	    map<int,int>mp;
	    for(int i=0;i<n;i++){
	        int x,y;
	        cin>>x>>y;
	        v.push_back({x,y});
	        s.insert(x);
	        s.insert(y);
	    }
	    int cur=1;
	    for(auto x:s){
	        mp[x]=cur;
	        cur++;
	    }
	    for(int i=0;i<n;i++){
	        v[i].first=mp[v[i].first];
	        v[i].second=mp[v[i].second];
	    }
	    vector<int>st(2*n+50),en(2*n+50);
	    for(int i=0;i<n;i++){
	        st[v[i].second]++;
	        en[v[i].first]++;
	    }
	    for(int i=1;i<2*n+50;i++){
	        st[i]+=st[i-1];
	    }
	    for(int j=2*n+40;j>=0;j--){
	        en[j]+=en[j+1];
	    }
	    int ans=2e6;
	    for(int i=0;i<n;i++){
	        ans=min(ans,st[v[i].first-1]+en[v[i].second+1]);
	    }
	    cout<<ans<<endl;
	    
	}

}
