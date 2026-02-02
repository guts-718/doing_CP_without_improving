#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	vector<int> turns(N);
	for(int i = 0; i < N; i++){
		cin >> A[i];
		int b = 0;
		while((1 << (b+1)) <= A[i]) b++;
		if(A[i] == (1 << b)){
			turns[i] = 2*b;
		} else if(A[i] == ((1 << b) + 1)){
			turns[i] = 2*b+1;
		} else {
			turns[i] = 2*b+2;
		}
	}
	vector<int> psum(N+1);
	for(int i = 0; i < N; i++){
		psum[i+1] = psum[i] + turns[i];
	}
	for(int q = 0; q < Q; q++){
		int l, r;
		cin >> l >> r;
		l--;
		int val = psum[r] - psum[l];
		cout << (val / 2) << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}