// Problem - https://codeforces.com/problemset/problem/580/C

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

const ll N = 1e5+7;
vector<ll> adj[N];
ll catnocat[N];
ll n, m, nocatpath = 0;

void dfs(ll k, ll p, ll catsofar) {
	if(catsofar > m) return;
	if(adj[k].size() == 1 && adj[k][0] == p && catsofar <= m) nocatpath++;
	for(auto v: adj[k]) {
		if(v == p) continue;
		(catnocat[v] == 1) ? dfs(v, k, catsofar+1) : dfs(v, k, 0);
	}
	return;
}

void program() {
	cin>>n>>m;
	fill(catnocat, catnocat + N, 0);
	for(ll i=0; i<n; i++) cin>>catnocat[i+1];
	for(ll i=0; i<n-1; i++) {
		ll x, y; cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, -1, catnocat[1]);
	cout<<nocatpath<<'\n';
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	// ll t;
	// cin >> t;
	// while(t--) 
	program();
}
