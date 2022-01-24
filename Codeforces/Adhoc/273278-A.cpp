// Problem - https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/A

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

struct segTree {
    int size;
    vector<ll> tree; // To store maximum sum on a segment
    vector<ll> prefix; // To store maximum prefix sum on a segment
    vector<ll> suffix; // To store maximum suffix sum on a segment
    vector<ll> sum; // To store total sum on a segment

    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.assign(size * 2, 0LL);
        prefix.assign(size * 2, 0LL);
        suffix.assign(size * 2, 0LL);
        sum.assign(size * 2, 0LL);
    }

    void build(vector<ll> &a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < int(a.size())) {
                tree[x] = a[lx];
                prefix[x] = a[lx];
                suffix[x] = a[lx];
                sum[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx)/2;
        build(a, 2*x + 1, lx, m);
        build(a, 2*x + 2, m, rx);
        tree[x] = max(tree[2*x + 1], max(tree[2*x + 2], suffix[2*x + 1] + prefix[2*x + 2]));
        prefix[x] = max(prefix[2*x + 1], sum[2*x + 1] + prefix[2*x + 2]);
        suffix[x] = max(suffix[2*x + 2], sum[2*x + 2] + suffix[2*x + 1]);
        sum[x] = sum[2*x + 1] + sum[2*x + 2];
    }

    void build(vector<ll> &a) {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x] = v;
            prefix[x] = v;
            suffix[x] = v;
            sum[x] = v;
            return;
        }
        int m = (lx + rx)/2;
        if(i<m) {
            set(i, v, 2*x + 1, lx, m);
        }
        else {
            set(i, v, 2*x + 2, m, rx);
        }
        tree[x] = max(tree[2*x + 1], max(tree[2*x + 2], suffix[2*x + 1] + prefix[2*x + 2]));
        prefix[x] = max(prefix[2*x + 1], sum[2*x + 1] + prefix[2*x + 2]);
        suffix[x] = max(suffix[2*x + 2], sum[2*x + 2] + suffix[2*x + 1]);
        sum[x] = sum[2*x + 1] + sum[2*x + 2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    ll maxSegment(int l, int r, int x, int lx, int rx) {
        if(lx >= l && rx <= r) return tree[x];
        else if(lx >= r || rx <= l) return 0LL;
        int m = (lx + rx) / 2;
        ll s1 = maxSegment(l, r, 2*x + 1, lx, m);
        ll s2 = maxSegment(l, r, 2*x + 2, m, rx);
        return max(s1, max(s2, suffix[2*x + 1] + prefix[2*x + 2]));
    }

    ll maxSegment(int l, int r) {
        return maxSegment(l, size, 0, 0, size);
    }
};

int main() {
    int n, m; cin>>n>>m;
    segTree st;
    st.init(n);
    vector<ll> a(n, 0);
    for(int i=0; i<n; i++) cin>>a[i];
    st.build(a);
    cout<<max(0LL, st.maxSegment(0, n))<<'\n';
    while(m--) {
        int i, v; cin>>i>>v;
        st.set(i, v);
        cout<<max(0LL, st.maxSegment(0, n))<<'\n';
    }
    return 0;
}
