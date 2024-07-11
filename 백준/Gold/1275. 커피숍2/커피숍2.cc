#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define pll pair<ll, ll>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

using namespace std;

ll init(vector<ll>& v, vector<ll>& tree, int node, int start, int end) {
    if (start == end) return tree[node] = v[start];
    int mid = (start + end) / 2;
    return tree[node] = init(v, tree, 2 * node, start, mid) + init(v, tree, 2 * node + 1, mid + 1, end);
}

ll query(vector<ll>& tree, int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right)   return tree[node];
    int mid = (start + end) / 2;
    return query(tree, 2 * node, start, mid, left, right) + query(tree, 2 * node + 1, mid + 1, end, left, right);
}

void update(vector<ll>& tree, int node, int start, int end, int index, ll diff) {
    if (index < start || end < index) return;
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, 2 * node, start, mid, index, diff);
        update(tree, 2 * node + 1, mid + 1, end, index, diff);
    }
    

}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    FOR(i, 0, n) {
        cin >> v[i];
    }
    vector<ll> tree(4 * n);
    init(v, tree, 1, 0, n - 1);

    ll x, y, a, b;
    FOR(_, 0, q) {
        cin >> x >> y >> a >> b;
        if (x > y) {
            cout << query(tree, 1, 0, n - 1, y - 1, x - 1) << endl;
        }
        else {
            cout << query(tree, 1, 0, n - 1, x - 1, y - 1) << endl;
        }
        
        ll diff = b - v[a - 1];
        update(tree, 1, 0, n - 1, a - 1, diff);
        v[a - 1] = b;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}