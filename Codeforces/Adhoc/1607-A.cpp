// Problem - https://codeforces.com/contest/1607/problem/A

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--) {
		string keyboard; cin>>keyboard;
		string test; cin>>test;
		map<char, int> mp;
		for(int i=0; i<keyboard.length(); i++) {
			mp[keyboard[i]] = i+1;
		}
		int sum = 0;
		for(int i=1; i<test.length(); i++) {
			sum += abs(mp[test[i]] - mp[test[i-1]]);
		}
		cout<<sum<<endl;
		mp.clear();
	}
}
