// Problem - https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/B

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

ll n, k;
vector<ll> a;

bool func(ll mid) {
	ll segments = 1;
	ll curr_sum = 0;
	for(ll i=0; i<n; i++) {
		if(curr_sum + a[i] > mid) {
			segments++;
			curr_sum = a[i];
			if(curr_sum > mid) return false;
		} 
		else curr_sum += a[i];
	}
	return segments <= k;
}

void program() {
	cin>>n>>k;
	ll sum = 0;
	for(ll i=0; i<n; i++) {
		ll x; cin>>x;
		a.push_back(x);
		sum += x;
	}
	ll l = -1; // left: func(mid) => Distance for which the k segmentation is not possible
	ll r = sum; // right: func(mid) => Distance for which the k and less segmentation is possible
	
	// while(!func(r)) {
	// 	r *= 2;
	// }
	
	while(r > l+1) {
		ll mid = (l+r)/2;
		if(func(mid)) r = mid; 
		else l = mid;
	}
	
	cout<<r<<'\n';
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    // lld t;
    // cin >> t;
    // while(t--) 
    program();
}
