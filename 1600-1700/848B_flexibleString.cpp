#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
string a, b;
string char_list;
bool mark[26];
ll ans, k;
 
ll count_matching_pair()
{
    ll tot_pair = 0, match_count = 0;
 
    for(ll i = 0; i < a.size(); i++) {
        if(a[i] == b[i] || mark[ a[i]-'a' ])
            match_count++;
        else {
            tot_pair += match_count*(match_count+1)/2;
            match_count = 0;
        }
    }
    tot_pair += match_count*(match_count+1)/2;
 
    return tot_pair;
}
 
void solve(ll pos, ll cnt)
{
    if(cnt > k) return;
 
    if(pos == char_list.size()) {
        if(cnt == k) ans = max(ans, count_matching_pair());
        return;
    }
 
    solve(pos+1, cnt);
 
    mark[ char_list[pos]-'a' ] = 1;
    solve(pos+1, cnt+1);
    mark[ char_list[pos]-'a' ] = 0;
}
 
int main()
{
    fastio;
    ll t;
    cin >> t;
 
    while(t--) {
        ll n; cin >> n >> k;
        cin >> a >> b;
 
        unordered_set <char> unq;
        for(auto &ch : a) unq.insert(ch);
 
        char_list.clear();
        for(auto &x : unq) char_list.pb(x);
 
        k = min(k, (ll)unq.size());
        memset(mark, 0, sizeof mark);
        ans = 0;
        solve(0, 0);
 
        cout << ans << EL;
    }
 
    return 0;
}