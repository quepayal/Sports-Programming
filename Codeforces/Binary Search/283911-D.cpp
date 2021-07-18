// Problem - https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D

#include <bits/stdc++.h>
using namespace std;

void program() {
	int n, m; cin>>n;
	vector<int> a(n, 0);
	for(int i=0; i<n; i++) cin>>a[i];
	cin>>m;
	//10 1 10 3 4
	//1 3 4 10 10
	sort(a.begin(), a.end());
	while(m--) {
		int k1, k2; cin>>k1>>k2;
		int ans = 0;
		//left -Inf and right Inf
		int l = -1, r = n;
		//Invariant
		// left < k and right >= k
		while(r > l+1) {
			int mid = (l + r) / 2;
			if(a[mid] < k1) l = mid;
			else r = mid;
		}
		ans -= r+1;
		
		//left -Inf and right Inf
		l = -1, r = n;
		//Invariant
		// left <= k and right > k
		while(r > l+1) {
			int mid = (l + r) / 2;
			if(a[mid] <= k2) l = mid;
			else r = mid;
		}
		ans += l+1;
		cout<<ans+1<<' ';
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
