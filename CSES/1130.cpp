// Problem - https://cses.fi/problemset/task/1130/

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

const ll N = 2e5 + 7;
vector<ll> adj[N];
ll arr[N][2];

void dfs(ll n, ll p) {
	//When node n is not included
	arr[n][0] = arr[n][1] = 0;
	for (auto m : adj[n]) {
		if(m == p) continue;
		if(arr[m][0] == -1 || arr[m][1] == -1) dfs(m, n);
		arr[n][0] += max(arr[m][0], arr[m][1]);
	}
	
	//When node n is included
	vector<ll> prefixSum;
	prefixSum.push_back(0);
	map<ll, ll> mp; ll cnt = 1;
	for(auto m: adj[n]) {
		if(m == p) continue;
		prefixSum.push_back(max(arr[m][0], arr[m][1]));
		mp[m] = cnt++;
	}
	ll pfSz = prefixSum.size() - 1;
	for(ll i = 1; i < prefixSum.size(); i++) {
		prefixSum[i] += prefixSum[i-1];
	}
	cnt = 1;
	for (auto m: adj[n]) {
		ll temp = 0;
		if(m == p) continue;
		temp += prefixSum[pfSz] - prefixSum[mp[m]] + prefixSum[mp[m] - 1];
		if(arr[m][0] == -1 || arr[m][1] == -1) dfs(m, n);
		temp += arr[m][0] + 1;
		arr[n][1] = max(arr[n][1], temp);
	}
}

void program() {
	ll n; cin>>n;
	fill(arr[0], arr[0] + N * 2, -1);
	for(int i=2; i<n+1; i++) {
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, -1);
	cout<<max(arr[1][0], arr[1][1])<<'\n';
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	// ll t;
	// cin >> t;
	// while(t--) 
	program();
}
