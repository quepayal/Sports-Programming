// Problem - https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/C

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

ll n, k;
vector<ll> a;

bool func(ll mid) {
	ll cows = 1;
	ll idx = 0;
	for(ll i=1; i<n; i++) {
		if(a[i] - a[idx] >= mid) {
			cows++;
			idx = i;
		}
	}
	return cows >= k;
}

void program() {
	cin>>n>>k;
	for(ll i=0; i<n; i++) {
		ll x; cin>>x;
		a.push_back(x);
	}
	ll l = 0; // left: func(mid) => Distance for which the k cows exist
	ll r = a[n-1]; // right: func(mid) => Distance for which the cows doesn't exist
	
	// while(!func(r)) {
	// 	r *= 2;
	// }
	
	while(r > l+1) {
		ll mid = (l+r)/2;
		if(func(mid)) l = mid; 
		else r = mid;
	}
	
	cout<<l<<'\n';
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    // lld t;
    // cin >> t;
    // while(t--) 
    program();
}
