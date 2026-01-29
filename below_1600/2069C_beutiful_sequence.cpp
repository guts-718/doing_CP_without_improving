#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

int md(int x){
  if(x>=mod){return (x-mod);}
  return x;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    int res=0;

    int c1=0;
    int c2=0;
    for(int i=0;i<n;i++){
      int x;
      cin >> x;
      if(x==1){c1++;}
      else if(x==2){
        c2=md(c2+c2);
        c2=md(c2+c1);
      }
      else if(x==3){
        res=md(res+c2);
      }
    }
    cout << res%mod << "\n";
  }
  return 0;
}