// Problem - https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/D

#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
using namespace std;
#define SIZE 2 * 100005

ll n, m, d;
vector<pair<ll, ll>> a [SIZE];
ll level [SIZE];
bool vis [SIZE];
vector<ll> pp(SIZE);

bool func(ll mid) {
	memset(vis, false , sizeof vis);
	pp.clear();
	level[1] = 0;
	queue<ll> q;
	q.push(1);
	pp[1] = -1;
	while(!q.empty()) {
		ll x = q.front();
		q.pop();
		
		for(auto k: a[x]) {
			ll node = k.first;
			ll edge = k.second;
			if(vis[node] == false && edge <= mid && level[x] < d) {
				level[node] = level[x] + 1;
				vis[node] = true;
				q.push(node);
				pp[node] = x;
			}
		}
	}
	return vis[n];
}

void program() {
	ll l = -1; // left: func(mid) => Distance for which the path from 1 -> n exist in atmost d edges
	ll r = 0; // right: func(mid) => Distance for which the path from 1 -> n doesn't exist in atmost d edges
	cin>>n>>m>>d;
	bool flag = false, check = false;
	for(ll i=0; i<m; i++) {
		ll n1, n2, w; cin>>n1>>n2>>w;
		r = max(r, w);
		if(n1 == 1) check = true;
		a[n1].push_back({n2, w});
	}
	
	if(!check){
		cout<<-1<<'\n';
		return;
	}
	
	// while(!func(r)) {
	// 	r *= 2;
	// }
	
	r++;
	while(r > l+1) {
		ll mid = (l+r)/2;
		if(func(mid)) {
			r = mid; 
			flag = true;
		}
		else l = mid;
	}
	
	if(!flag) {
		cout<<-1<<'\n';
	}
	else {
		vector<ll> path;
	    for (ll v = n; v != -1; v = pp[v])
	        path.push_back(v);
	    reverse(path.begin(), path.end());
	    cout << (ll)path.size()-1<<'\n';
	    for (ll v : path)
	        cout << v << " ";
	    cout<<'\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    // lld t;
    // cin >> t;
    // while(t--) 
    program();
}
