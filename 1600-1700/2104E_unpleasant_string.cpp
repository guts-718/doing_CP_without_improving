#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    map<char, TrieNode*> children;
    vector<int> ids;
};

void insert(TrieNode *r, const string &w, int id) {
    TrieNode *c = r;
    for (char ch : w) {
        if (!c->children.count(ch))
            c->children[ch] = new TrieNode();
        c = c->children[ch];
    }
    c->ids.push_back(id);
}

vector<vector<int>> buildNext(const string &s) {
    int n = s.size();
    vector<vector<int>> nx(n+2, vector<int>(26, -1));

    for (int i = n-1; i >= 0; i--) {
        nx[i] = nx[i+1];
        nx[i][s[i]-'a'] = i;
    }
    return nx;
}

void dfs(TrieNode *u, int pos,
         vector<int> &ans,
         const vector<vector<int>> &nx) {

    for (int id : u->ids)
        ans[id] = pos;  

    for (auto &[ch, v] : u->children) {
        int nxt = (pos == -1 ? nx[0][ch-'a']
                             : nx[pos+1][ch-'a']);
        if (nxt != -1)
            dfs(v, nxt, ans, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int q;
    cin >> q;
    vector<string> v(q);
    for (int i = 0; i < q; i++)
        cin >> v[i];

    TrieNode *root = new TrieNode();
    for (int i = 0; i < q; i++)
        insert(root, v[i], i);

    auto nx = buildNext(s);
    vector<int> ans(q, -1);
    vector<int>help(n+2,0);
    int cnt=0;
    set<char>st;
    
    for(int i=n-1;i>=0;i--){
        st.insert(s[i]);
        if(st.size()==k){
            cnt++;
            st.clear();
        }
        help[i]=cnt;
    }
    dfs(root, -1, ans, nx);

    for (int x : ans)
        if(x<0)cout<<0<<endl;
        else cout<<help[x+1]+1 << '\n';  

    return 0;
}
