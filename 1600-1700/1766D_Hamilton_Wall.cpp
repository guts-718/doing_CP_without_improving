#include <bits/stdc++.h>
using namespace std;

constexpr int N = std::sqrt(1E9);
std::vector<int> isprime(N + 1, 1);
std::vector<int> primes;


vector<int>pfa(int x){
    vector<int>b;
    for (auto p : primes) {
            if (p * p > x) {
                break;
            }
            if (x % p == 0) {
                b.push_back(p);
                while (x % p == 0) {
                    x /= p;
                }
            }
        }
        if (x > 1) {
            b.push_back(x);
        }
    return b;
}



int main() {
    
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    for (int i = 2; i <= N; i++) {
        if (isprime[i]) {
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > N) {
                break;
            }
            isprime[i * p] = 0;
            if (i % p == 0) {
                break;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
     int a,b;
     cin>>a>>b;
     if(__gcd(a,b)!=1){
         cout<<0<<endl;
         continue;
     }
     if(a%2==0 && b%2==0){
         cout<<0<<endl;
         continue;
     }
     if(a%2==1 && b%2==1){
         cout<<1<<endl;
         continue;
     }
     if(abs(b-a)==1){
         cout<<-1<<endl;
         continue;;
         
     }
     int x=abs(b-a);
     vector<int>pf=pfa(x);
     int ans=1e18;
     for(auto x:pf){
         ans=min(ans,x-a%x);
     }
     if(ans>1e9){
         cout<<-1<<endl;
         
     }else cout<<ans<<endl;
       
       
    }
    return 0;
}
