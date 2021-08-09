// Problem - https://codeforces.com/contest/1336/problem/A

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

const int N = 223456;
vector<int> adj[N];
int a[N];

int dfs(int n, int p, int k) {
	int treesz = 1;
	for(auto v: adj[n]) {
		if(v == p) continue;
		treesz += dfs(v, n, k+1);
	}
	a[n] = k - treesz; 
	return treesz;
}

void program() {
	int n, k; cin>>n>>k;
	for(int i=1; i<n; i++) {
		int u, v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fill(a, a+N, 0);
	dfs(1, -1, 1);
	sort(a+1, a+n+1);
	ll ans = 0;
	for (int i=0; i < k; i++)
		ans += a[n-i];
	cout<<ans<<'\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	program();
}
