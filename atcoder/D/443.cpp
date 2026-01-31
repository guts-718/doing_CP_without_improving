#include <bits/stdc++.h>
using namespace std;

int main() {
   
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> R(N), F(N);
        long long ans = 0;
        for (int i = 0; i < N; i++) {
            cin >> R[i];
            F[i] = R[i];
        }

        for (int i = 1; i < N; i++) {
            F[i] = min(F[i], 1 + F[i-1]);
        }
        for (int i = N-2; i >= 0; i--) {
            F[i] = min(F[i], 1 + F[i+1]);
        }

       
        for (int i = 0; i < N; i++) {
            ans += R[i] - F[i];
        }

        cout << ans << endl;
    }
    return 0;
}
