// Problem - https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A

#include <bits/stdc++.h>
using namespace std;

void program() {
	int n, m; cin>>n>>m;
	vector<int> a(n, 0);
	for(int i=0; i<n; i++) cin>>a[i];
	while(m--) {
		int k; cin>>k;
		int l = 0, r = n-1;
		int flag = 1;
		while(l<=r) {
			int mid = (l + r + 1)/2;
			if(a[mid] == k) {
				cout<<"YES\n";
				flag = 0;
				break;
			}
			else if(a[mid] > k) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		if(flag) cout<<"NO\n";
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
