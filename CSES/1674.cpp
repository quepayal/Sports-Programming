// Problem - https://cses.fi/problemset/task/1674

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

const int N = 2e5 + 7;
vector<int> adj[N];
int arr[N];

int dfs(int n) {
	if(adj[n].size() == 0) return 0;
	for (auto m : adj[n]) {
		arr[n] += dfs(m) + 1;
	}
	return arr[n];
}

void program() {
	int n; cin>>n;
	fill_n(arr, N, 0);
	for(int i=2; i<n+1; i++) {
		int x; cin>>x;
		adj[x].push_back(i);
	}
	dfs(1);
	for(int m=1; m<n+1; m++) cout<<arr[m]<<" ";
	cout<<'\n';
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	// ll t;
	// cin >> t;
	// while(t--) 
	program();
}
