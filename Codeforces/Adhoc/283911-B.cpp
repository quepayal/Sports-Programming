// Problem - https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B

#include <bits/stdc++.h>
using namespace std;

void program() {
	int n, m; cin>>n>>m;
	vector<int> a(n, 0);
	for(int i=0; i<n; i++) cin>>a[i];
	while(m--) {
		int k; cin>>k;
		//left -Inf and right Inf
		int l = -1, r = n;
		//Invariant
		// left <= k and right > k
		while(r > l+1) {
			int mid = (l + r) / 2;
			if(a[mid] <= k) l = mid;
			else r = mid;
		}
		cout<<l+1<<'\n';
	}
	
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin >> t;
    //while(t--) 
    program();
}
