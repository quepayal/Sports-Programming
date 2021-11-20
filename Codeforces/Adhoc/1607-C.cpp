// Problem - https://codeforces.com/contest/1607/problem/C

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vector<int> a(n, 0);
		for(int i=0; i<n; i++) cin>>a[i];
		sort(a.begin(), a.end());
		for(int i=n-1; i>0; i--) a[i] = a[i] - a[i-1];
		sort(a.rbegin(), a.rend());
		cout<<a[0]<<endl;
	}
}
