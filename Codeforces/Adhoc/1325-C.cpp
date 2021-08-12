// Problem - https://codeforces.com/problemset/problem/1325/C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;

void program() {
	int n; cin>>n;
	pair<int, int> adj[n];
	int deg[n+1];
	int mxDeg = 0, node = 1;
	fill(deg, deg+n+1, 0);
	for(int i=1; i<n; i++) {
		int u, v; cin>>u>>v;
		adj[i] = {u, v};
		deg[u]++; deg[v]++;
		if(deg[u] > deg[v]) {
			if(deg[u] > mxDeg) node = u, mxDeg = deg[u];
		}
		else if(deg[v] > mxDeg) node = v, mxDeg = deg[v];
	}
	if(mxDeg < 3) {
		for(int i=1; i<n; i++) {
			cout<<i-1<<'\n';
		}
		return;
	}
	int k1 = 0, k2 = 3;
	for(auto m: adj) {
		if(m.first == 0 || m.second == 0) continue;
		if((m.first == node || m.second == node) && k1 < 3) cout<<k1++<<'\n';
		else cout<<k2++<<'\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	program();
}
