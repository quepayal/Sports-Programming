// Problem - https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

struct segtree {
	int size;
	vector<ll> sums;
	void build(vector<int> &a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < int(a.size())) {
				sums[x] = a[lx];
			}
			return;
		}
		int m = (lx + rx)/2;
		build(a, 2*x + 1, lx, m);
		build(a, 2*x + 2, m, rx);
		sums[x] = sums[2*x + 1] + sums[2*x + 2];
		return;
	}
	
	void build(vector<int> &a) {
		build(a, 0, 0, size);
	}
	
	void init(int n) {
		size = 1;
		while(size < n) size *= 2;
		sums.assign(2*size, 0LL);
	}
	
	void set(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1) {
			sums[x] = v;
			return;
		}
		int m = (lx+rx)/2;
		if(i<m) {
			set(i, v, 2 * x + 1, lx, m);
		}
		else {
			set(i, v, 2 * x + 2, m, rx);
		}
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}
	
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}
	
	ll sum(int l, int r, int x, int lx, int rx) {
		if(lx >= r || l >= rx) return 0;
		if(lx >= l && rx <= r) return sums[x];
		int m = (lx + rx)/2;
		ll s1 = sum(l, r, 2*x + 1, lx, m);
		ll s2 = sum(l, r, 2*x + 2, m, rx);
		return s1 + s2;	
	}
	
	ll sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}
};
	
void program() {
	int n, m; cin>>n>>m;
	segtree st;
	st.init(n);
	vector<int> a(n);
	for(int i=0; i<n; i++) cin>>a[i];
	st.build(a);
	
	while(m--) {
		int op;
		cin>>op;
		if(op == 1) {
			int i, v; cin>>i>>v;
			st.set(i, v);
		}
		else {
			int l, r; cin>>l>>r;
			cout<<st.sum(l, r)<<'\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	program();
}
