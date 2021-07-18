// Problem - https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

ll n, k;
vector<lld> a;

bool func(lld m) {
	ll sum = 0;
	for(ll i=0; i<n; i++) {
		sum += (ll)(a[i]/m);
	}
	return sum >= k;
}

void program() {
	cin>>n>>k;
	for(ll i=0; i<n; i++) {
		lld x; cin>>x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	lld l, r;
	l = 0; // func(left) >= k
	r = a[n-1];  // func(right) < k
	
	for(ll i=0; i<=100; i++) {
		lld mid = (l+r)/2.0;
		if(func(mid)) l = mid;
		else r = mid;
	}
	cout<< fixed << setprecision(10) << l <<'\n';
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while(t--) 
    program();
}
