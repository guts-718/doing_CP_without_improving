#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // positions of each value
        unordered_map<int, queue<int>> pos;
        pos.reserve(n);

        // last occurrence
        unordered_map<int, int> last;
        last.reserve(n);

        for (int i = 0; i < n; i++) {
            pos[a[i]].push(i);
            last[a[i]] = i;
        }

        // alive values
        set<int> alive;
        for (auto &p : last) alive.insert(p.first);

        // multiset of last occurrences
        multiset<int> lastPos;
        for (auto &p : last) lastPos.insert(p.second);

        vector<int> ans;
        int curPos = -1;
        bool odd = true;

        while (!alive.empty()) {
            bool picked = false;

            if (odd) {
                // odd position → largest first
                for (auto it = alive.rbegin(); it != alive.rend(); ++it) {
                    int x = *it;
                    if (pos[x].empty()) continue;

                    int idx = pos[x].front();
                    if (idx <= curPos) continue;

                    // feasibility check
                    lastPos.erase(lastPos.find(last[x]));
                    int mnLast = lastPos.empty() ? INT_MAX : *lastPos.begin();
                    lastPos.insert(last[x]);

                    if (idx < mnLast) {
                        // pick x
                        ans.push_back(x);
                        curPos = idx;

                        // remove outdated indices
                        for (int y : alive) {
                            while (!pos[y].empty() && pos[y].front() <= curPos)
                                pos[y].pop();
                        }

                        lastPos.erase(lastPos.find(last[x]));
                        alive.erase(x);
                        picked = true;
                        break;
                    }
                }
            } else {
                // even position → smallest first
                for (auto it = alive.begin(); it != alive.end(); ++it) {
                    int x = *it;
                    if (pos[x].empty()) continue;

                    int idx = pos[x].front();
                    if (idx <= curPos) continue;

                    lastPos.erase(lastPos.find(last[x]));
                    int mnLast = lastPos.empty() ? INT_MAX : *lastPos.begin();
                    lastPos.insert(last[x]);

                    if (idx < mnLast) {
                        ans.push_back(x);
                        curPos = idx;

                        for (int y : alive) {
                            while (!pos[y].empty() && pos[y].front() <= curPos)
                                pos[y].pop();
                        }

                        lastPos.erase(lastPos.find(last[x]));
                        alive.erase(x);
                        picked = true;
                        break;
                    }
                }
            }

            // flip parity
            odd = !odd;
        }

        // output answer
        cout<<ans.size()<<endl;
        for (int x : ans) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
