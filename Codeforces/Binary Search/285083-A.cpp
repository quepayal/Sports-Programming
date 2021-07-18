// Problem - https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/A

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

lld n;
vector<pair<lld, lld>> a;

bool func(lld mid) {
	lld low = LLONG_MIN, high = LLONG_MAX;
	//vector<pair<lld, lld>> segment;
	for(lld i=0; i<n; i++) {
		lld x = a[i].first; 
		lld v = a[i].second;
		low = max(x - mid * v, low);
		high = min(x + mid * v, high);
		//segment.push_back({x - mid * v, x + mid * v});
	}
	// sort(segment.begin(), segment.end(), [] (const pair<int, int> &m, const pair<int, int> &k) -> bool {
	// 	return m.first >= k.first;
	// });
	// // for(auto t: segment) cout<<t.first<<" : "<<t.second<<"|";
	// // cout<<'\n';
	// lld low = segment[0].first;
	// sort(segment.begin(), segment.end(), [] (const pair<int, int> &m, const pair<int, int> &k) -> bool {
	// 	return m.second <= k.second;
	// });
	// // for(auto t: segment) cout<<t.first<<" : "<<t.second<<"|";
	// // cout<<'\n';
	// lld high = segment[0].second;
	
	return low <= high;
}

void program() {
	cin>>n;
	for(lld i=0; i<n; i++) {
		lld x, v; cin>>x>>v;
		a.push_back({x, v});
	}
	lld l = -1; // left: func(mid) => < Time for which the intersection is not possible
	lld r = 1; // right: func(mid) => >= Time for which the intersection is possible
	
	while(!func(r)) {
		r *= 2;
	}
	
	for(int i=0; i<100; i++) {
		lld mid = (l+r)/2.0;
		if(func(mid)) r = mid; 
		else l = mid;
	}
	
	cout<<fixed<<setprecision(16)<<r<<'\n';
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    // lld t;
    // cin >> t;
    // while(t--) 
    program();
}
