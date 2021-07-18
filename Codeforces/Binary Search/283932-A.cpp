// Problem - https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A

#include <bits/stdc++.h>
using namespace std;

long long w, h, n;

bool func(long long k) {
	return floor(k/w)* floor(k/h) >= n;
}

void program() {
	cin>>w>>h>>n;
	long long l, r;
	l = -1; // left < ans
	long long k = 1;
	while(k < max(n*w, n*h)) {
		k *= 2;
	}
	r = k; // right >= ans
	while(r > l+1) {
		long long mid = (l+r)/2;
		if(func(mid)) r = mid;
		else l = mid;
	}
	cout<<r<<'\n';
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while(t--) 
    program();
}
