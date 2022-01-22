// Problem - https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

ll n, x, y;

bool func(ll time) {
	ll leftTime = max(0ll, time-x);
	ll copies = 0;
	if(time >= x) copies = 1;
	
	copies += leftTime/x + leftTime/y;
	return copies >= n;
}

void program() {
	cin>>n>>x>>y;
	ll l, r;
	l = 0; // func(left_time) < n
	r = max(x, y) * n;  // func(right_time) >= n
	if(x > y) {
		x = x + y;
		y = x - y;
		x = x - y;
	}
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
    // int t;
    // cin >> t;
    // while(t--) 
    program();
}
