// Problem - https://codeforces.com/problemset/problem/339/D

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

struct segtree {
	int size;
	vector<ll> Xor;
	void build(vector<int> &a, int x, int lx, int rx, int k) {
		if(rx - lx == 1) {
			if(lx < int(a.size())) {
				Xor[x] = a[lx];
			}
			return;
		}
		int m = (lx + rx)/2;
		build(a, 2*x + 1, lx, m, k-1);
		build(a, 2*x + 2, m, rx, k-1);
		(k & 1) ? Xor[x] = Xor[2*x + 1] | Xor[2*x + 2] : Xor[x] = Xor[2*x + 1] ^ Xor[2*x + 2];
		return;
	}
	
	void build(vector<int> &a, int n) {
		build(a, 0, 0, size, n);
	}
	
	void init(int n) {
		size = 1;
		while(size < n) size *= 2;
		Xor.assign(2*size, 0LL);
	}
	
	void set(int i, int v, int x, int lx, int rx, int k) {
		if(rx - lx == 1) {
			Xor[x] = v;
			return;
		}
		int m = (lx+rx)/2;
		if(i<m) {
			set(i, v, 2*x + 1, lx, m, k-1);
		}
		else {
			set(i, v, 2*x + 2, m, rx, k-1);
		}
		(k & 1) ? Xor[x] = Xor[2*x + 1] | Xor[2*x + 2] : Xor[x] = Xor[2*x + 1] ^ Xor[2*x + 2];
	}
	
	void set(int i, int v, int n) {
		set(i, v, 0, 0, size, n);
	}
};
	
void program() {
	int n, m; cin>>n>>m;
	segtree st;
	st.init(1<<n);
	vector<int> a(1<<n);
	for(int i=0; i<(1<<n); i++) cin>>a[i];
	st.build(a, n);

	while(m--) {
		int i, v; cin>>i>>v;
		st.set(i-1, v, n);
		cout<<st.Xor[0]<<'\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	program();
}
