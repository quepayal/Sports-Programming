// Problem - https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

struct segtree {
	int size;
	vector<int> minm;
	vector<int> cnt;
	
	void build(vector<int> &a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < int(a.size())) {
				minm[x] = a[lx];
				cnt[x] = 1;
			}
			return;
		}
		int m = (lx + rx)/2;
		build(a, 2*x + 1, lx, m);
		build(a, 2*x + 2, m, rx);
		minm[x] = min(minm[2*x + 1], minm[2*x + 2]);
		if(minm[2*x + 1] == minm[2*x + 2]) cnt[x] = cnt[2*x + 1] + cnt[2*x + 2];
		else if(minm[2*x + 1] < minm[2*x + 2]) cnt[x] = cnt[2*x + 1];
		else cnt[x] = cnt[2*x + 2];
		return;
	}
	
	void build(vector<int> &a) {
		build(a, 0, 0, size);
	}
	
	void init(int n) {
		size = 1;
		while(size < n) size *= 2;
		minm.assign(2*size, 0LL);
		cnt.assign(2*size, 0LL);
	}
	
	void set(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1) {
			minm[x] = v;
			cnt[x] = 1;
			return;
		}
		int m = (lx+rx)/2;
		if(i<m) {
			set(i, v, 2 * x + 1, lx, m);
		}
		else {
			set(i, v, 2 * x + 2, m, rx);
		}
		minm[x] = min(minm[2 * x + 1], minm[2 * x + 2]);
		if(minm[2*x + 1] == minm[2*x + 2]) cnt[x] = cnt[2*x + 1] + cnt[2*x + 2];
		else if(minm[2*x + 1] < minm[2*x + 2]) cnt[x] = cnt[2*x + 1];
		else cnt[x] = cnt[2*x + 2];
	}
	
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}
	
	pair<int, int> findmin(int l, int r, int x, int lx, int rx) {
		if(lx >= r || l >= rx) return {INT_MAX, 0};
		if(lx >= l && rx <= r) return {minm[x], cnt[x]};
		int m = (lx + rx)/2;
		auto m1 = findmin(l, r, 2*x + 1, lx, m);
		auto m2 = findmin(l, r, 2*x + 2, m, rx);
		if(m1.first == m2.first) return {m1.first, m1.second + m2.second};
		else if(m1.first < m2.first) return m1;
		else return m2;
	}
	
	pair<int, int> findmin(int l, int r) {
		return findmin(l, r, 0, 0, size);
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
			auto p = st.findmin(l, r);
			cout<<p.first<<" "<<p.second<<'\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	program();
}
