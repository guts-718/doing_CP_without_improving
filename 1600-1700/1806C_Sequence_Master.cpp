#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=400005;
const ll inf=2e18;

ll a[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		ll ans=0,sum=0;
		for(int i=1;i<=n*2;i++) {
			cin>>a[i];
			ans+=abs(a[i]);
			sum+=abs(a[i]-(-1));
		}
		if(n==1) {
			ans=min(ans,abs(a[1]-a[2]));
		}
		if(n==2) {
			ans=min(ans,abs(a[1]-2)+abs(a[2]-2)+abs(a[3]-2)+abs(a[4]-2));
		}
		if(n%2==0) {
			for(int i=1;i<=n*2;i++) {
				ans=min(ans,sum-abs(a[i]-(-1))+abs(a[i]-n));
			}
		}
		cout<<ans<<"\n";
	}
}