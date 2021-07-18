// Problem - https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

ll m, n;
vector<pair<pair<ll, ll>, ll>> a;

bool func(ll time) {
	ll balloons = 0;
	for(int i=0; i<n; i++) {
		ll t = a[i].first.first;
		ll z = a[i].first.second;
		ll y = a[i].second;
		ll qou = time / (z * t + y);
		ll rem = time - (z * t + y) * qou;
		balloons += qou * z + min(z, rem / t);
	}
	return balloons >= m;
}

void program() {
	cin>>m>>n;
	ll l, r;
	l = -1; // left : func(time) < m balloons
	r = 1;  // right : func(time) >= m balloons
	for(int i=0; i<n; i++) {
		ll t, y, z; cin>>t>>z>>y;
		a.push_back({{t, z}, y});
	}
	
	while(!func(r)) {
		r *= 2;
	}
	
	while(r > l+1) {
		ll mid = (l+r)/2;
		if(func(mid)) r = mid;
		else l = mid;
	}
	cout<<r<<'\n';
	
	ll balloons = m;
	
	for(ll i = 0; i < n; i++) {
		ll t = a[i].first.first;
		ll z = a[i].first.second;
		ll y = a[i].second;
		ll qou = r / (z * t + y);
		ll rem = r - (z * t + y) * qou;
		if(balloons <= 0) {
			cout << 0 << " ";
			continue;
		}
		cout << min(qou * z + min(z, rem / t), balloons) << " ";
		balloons -= qou * z + min(z, rem / t);
	}
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while(t--) 
    program();
}
