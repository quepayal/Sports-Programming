// Problem - https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/F

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;

string t, p;
vector<int> a;

bool func(int m) {
	string s;
	vector<pair<char, int>> str;
	for(int i=0; i<t.length(); i++) {
		str.push_back({t[i], 1});
	}
	for(int i=0; i<m; i++) {
		str[a[i]-1].second = 0;
	}
	for(int i=0; i<str.size(); i++) {
		if(str[i].second) s += str[i].first;
	}
	int len = s.length();
	int p_len = p.length();
	int k = 0;
	for(int i=0; i<len && k<p_len; i++) {
		if(s[i] == p[k]) k++;
	}
	//cout<<"m: "<<m<<" t :"<<s<<" k : "<<k<<endl;
	if(k >= p_len) return true;
	return false;
}

void program() {
	cin>>t>>p;
	for(int i=0; i<t.length(); i++) {
		int x; cin>>x;
		a.push_back(x);
	}
	int l, r;
	l = -1; // left : func(mid) <= Petya can still make the string P
	r = t.length();  // right : func(mid) > Petya cannot make the string P 
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
    // int t;
    // cin >> t;
    // while(t--) 
    program();
}
