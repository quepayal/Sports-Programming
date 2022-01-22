// Problem - https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/H

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

string s;
ll nb, ns, nc, pb, ps, pc, rouble;

bool func(ll mid) {
	ll cnt[3] = {0LL, 0LL, 0LL};
	for(int i=0; i<s.size(); i++) {
		(s[i] == 'B') ? cnt[0] += 1 : (s[i] == 'S') ? cnt[1] += 1 : cnt[2] += 1;
	}
	ll needB = 0, needS = 0, needC = 0;
	needB = max(0LL, mid * cnt[0] - nb);
	needS = max(0LL, mid * cnt[1] - ns);
	needC = max(0LL, mid * cnt[2] - nc);
	ll money = rouble - (needB*pb + needS*ps + needC*pc);
	return (money >= 0);
}

void program() {
	cin>>s>>nb>>ns>>nc>>pb>>ps>>pc>>rouble;
	ll l = 0; // left: func(mid) => atleast >= mid Hamburgers can be formed
	ll r = 1; // right: func(mid) => Less then < mid Hamburgers can be formed
	
	while(func(r)) {
		r *= 2;
	}
	//cout<<r<<'\n';
	
	while(r > l+1) {
		ll mid = (l+r) / 2;
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
