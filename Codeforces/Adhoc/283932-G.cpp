// Problem - https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/G

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

ll k, n;
vector<ll> a;

bool func(ll m) {
	ll slot = m * k;
	for(ll i=0; i<n; i++) {
		slot -= min(m, a[i]);
	}
	return slot <= 0;
}

void program() {
	cin>>k>>n;
	for(ll i=0; i<n; i++) {
		ll x; cin>>x;
		a.push_back(x);
	}
	
	ll l, r;
	l = 0; // left : func(mid) <= Students council can form with existing configuration
	r = 1;  // right : func(mid) > Students council cannot form with existing configuration
	
	while(func(r)) {
		r *= 2;
	}
	
	while(r > l+1) {
		lld mid = (l+r)/2;
		if(func(mid)) l = mid;
		else r = mid;
	}
	cout<<l<<'\n';
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    // ll t;
    // cin >> t;
    // while(t--) 
    program();
}
