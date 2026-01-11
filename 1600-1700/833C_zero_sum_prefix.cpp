#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
constexpr int N=2e5+5;
int n,a[N];ll s[N];
inline void ct(){
	cin>>n;int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];s[i]=s[i-1]+a[i];
	}
	map<ll,int>p;
	for(int i=n;i>=1;i--){
		p[s[i]]++;
		if(!a[i]){
			int mx=0;
			for(auto k:p)mx=max(mx,k.second);
			ans+=mx;
			p.clear();
		}
	}
	ans+=p[0];cout<<ans<<'\n';
}
int main(){
	int T;cin>>T;
	while(T--)ct();
	return 0;
}
