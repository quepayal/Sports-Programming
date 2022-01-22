// Problem - https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

lld C;

bool func(lld m) {
	lld eq = m*m + sqrt(m);
	return eq >= C;
}

void program() {
	cin>>C;
	lld l, r;
	l = -1; // left : func(x) < C 
	r = C;  // right : func(x) >= C 
	
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
    // int t;
    // cin >> t;
    // while(t--) 
    program();
}
