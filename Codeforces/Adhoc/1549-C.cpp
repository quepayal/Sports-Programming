// Problem - https://codeforces.com/contest/1549/problem/C

#include <bits/stdc++.h>
#include <algorithm>
typedef long long ll;
typedef long double lld;
using namespace std;

void program() {
	int n, m; cin>>n>>m;
	int deg[n];
	fill(deg, deg+n, 0);
	int res = n;
	while(m--) {
		int u, v; cin>>u>>v;
		if(u>v) swap(u, v);
		if(deg[u] == 0) res--;
		deg[u] += 1;
	}
	int q; cin>>q;
	while(q--) {
		int qtype; cin>>qtype;
		if(qtype == 1) {
			int u, v; cin>>u>>v;
			if(u>v) swap(u, v);
			if(deg[u] == 0) res--;
			deg[u] += 1;
		}
		else if(qtype == 2) {
			int u, v; cin>>u>>v;
			if(u>v) swap(u, v);
			if(deg[u] == 1) res++;
			deg[u] -= 1;
		}
		else cout<<res<<'\n';
	}
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	// ll t;
	// cin >> t;
	// while(t--) 
	program();
}
