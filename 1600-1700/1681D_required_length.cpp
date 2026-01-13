#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

/* ---------- custom hash to avoid hacking ---------- */
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll n, x;
ll ans;
unordered_map<ll, ll, custom_hash> dp;

/* count digits */
ll digits(ll v) {
    if (v == 0) return 1;
    ll cnt = 0;
    while (v) {
        v /= 10;
        cnt++;
    }
    return cnt;
}

void solve(ll num, ll cnt) {
    if (cnt >= ans) return;
    if (digits(num) > n) return;

    if (dp.count(num) && dp[num] <= cnt) return;
    dp[num] = cnt;

    if (digits(num) == n) {
        ans = min(ans, cnt);
        return;
    }

    vector<int> digs;
    ll temp = num;
    while (temp) {
        digs.push_back(temp % 10);
        temp /= 10;
    }
    sort(digs.rbegin(),digs.rend());
    for (int d : digs) {
        if (d > 1) {
            solve(num * d, cnt + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    ans = INF;
    dp.clear();

    solve(x, 0);

    cout << (ans >= INF ? -1 : ans) << "\n";
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
#define kirTxn ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
#define all(a) a.begin(), a.end()
#define pvec(v) for(auto i:v) cout<<i<<" "; cout<<endl;
#define pmap(mp) for(auto i:mp) cout<<i.first<<" -> "<<i.second<<endl; cout<<endl;

int count(int n){
    int ans=0;
    while(n){
        n/=10;
        ans++;
    }
    return ans;
}

int x, n;
map<int, int> dp;

int fun(int num) {
    // Base cases

    if (floor(log10f(num)) + 1 > n) return dp[num] = 1e9;
    if (count(num) == n) return dp[num] = 0;

    if (dp.find(num) != dp.end()) return dp[num];
    int ans = 1e9; 
    int tmp = num;
    int dig = 0;
    vector<int> digs;
    while (tmp) {
        dig = tmp % 10;
        digs.push_back(dig);
        tmp /= 10;
    }
    sort(digs.rbegin(),digs.rend());

    for(int i=0;i<log2(x)+1 &&i<digs.size();i++)
        if (digs[i] > 1 && num*digs[i]>0) { 
            ans = min(ans, 1 + fun(num * digs[i]));
        }

    return dp[num] = ans;
}

void solution(int test_num){
    cin>>n>>x;
    fun(x);
    if(dp[x]==1e9) dp[x]=-1;
    cout<<dp[x]<<endl;
    dp.clear();
}


/* Main()  function */
signed main(){
    kirTxn;
    int t=1;
    for(int i=1;i<t+1;i++){
         solution(i);
         }
    return 0;
}



#include<bits/stdc++.h>

using namespace std;

int main()
{   
    int n;
    cin >> n;
    long long v;
    cin >> v;
    queue<long long> q;
    map<long long, int> dist;
    dist[v] = 0;
    q.push(v);
    while(!q.empty())
    {
        long long k = q.front();
        q.pop();
        string s = to_string(k);
        if(s.size() == n)
        {
            cout << dist[k] << endl;
            return 0;
        }
        for(auto x : s)
        {
            if(x == '0') continue;
            long long w = k * int(x - '0');
            if(!dist.count(w))
            {
                dist[w] = dist[k] + 1;
                q.push(w);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

/* ---------- custom hash to avoid hacking ---------- */
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll n, x;
ll ans;
unordered_map<ll, ll, custom_hash> dp;

/* count digits */
ll digits(ll v) {
    if (v == 0) return 1;
    ll cnt = 0;
    while (v) {
        v /= 10;
        cnt++;
    }
    return cnt;
}

void solve(ll num, ll cnt) {
    if (cnt >= ans) return;
    if (digits(num) > n) return;

    if (dp.count(num) && dp[num] <= cnt) return;
    dp[num] = cnt;

    if (digits(num) == n) {
        ans = min(ans, cnt);
        return;
    }

    vector<int> digs;
    ll temp = num;
    while (temp) {
        digs.push_back(temp % 10);
        temp /= 10;
    }
    sort(digs.rbegin(),digs.rend());
    for (int d : digs) {
        if (d > 1) {
            solve(num * d, cnt + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    ans = INF;
    dp.clear();

    solve(x, 0);

    cout << (ans >= INF ? -1 : ans) << "\n";
    return 0;
}
