// Problem - https://codeforces.com/problemset/problem/431/C

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

// Recursion Dp[sum][hasWeightofAtleast d]
// Initial condition - Dp[0][0] = 1, Dp[0][1] = 0
// Dp[n][0] = Dp[n-1][0] + Dp[n-2][0] + ... + Dp[n-min(d-1, n)][0]
// Dp[n][1] = Dp[n-1][1] + Dp[n-2][1] + ... + Dp[n-min(k, n)][1] + Dp[n-d][0] + Dp[n-(d+1)][0] + ... + Dp[n-min(k, n)][0]

const ll N = 1e5+7;
const ll Mod = 1e9+7;
ll n, k, d;
ll dp[N][2];

ll ktree(ll sum, ll m) {
	if(dp[sum][m] != -1) return dp[sum][m];
	dp[sum][m] = 0;
	if(m == 0) {
		ll t = min(d-1, sum) % Mod;
		for(ll i=1; i<=t; i++) dp[sum][m] = (dp[sum][m] + ktree(sum-i, 0)) % Mod;
		return dp[sum][m];
	}
	
	ll t = min(k, sum) % Mod;
	for(ll i=1; i<=t; i++) dp[sum][m] = (dp[sum][m] + ktree(sum-i, 1)) % Mod;
	for(ll i=d; i<=t; i++) dp[sum][m] = (dp[sum][m] + ktree(sum-i, 0)) % Mod;
	return dp[sum][m];
}

void program() {
	fill_n(&dp[0][0], N * 2, -1);
	dp[0][0] = 1;
	dp[0][1] = 0;
	cin>>n>>k>>d;
	cout<<ktree(n, 1)<<'\n';
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	// ll t;
	// cin >> t;
	// while(t--) 
	program();
}
