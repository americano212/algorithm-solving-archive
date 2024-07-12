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

ll query(vector<ll>& tree, int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(tree, 2 * node, start, mid, left, right) + query(tree, 2 * node + 1, mid + 1, end, left, right);
}

void modify(vector<ll>& tree, int node, int start, int end, int index, ll diff) {
    if (index < start || end < index) return;
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        modify(tree, 2 * node, start, mid, index, diff);
        modify(tree, 2 * node + 1, mid + 1, end, index, diff);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> v(n, 0);
    vector<ll> tree(n * 4, 0);

    ll a, b, c;
    FOR(_, 0, m) {
        cin >> a >> b >> c;
        if (a) {
            ll diff = c - v[b - 1];
            modify(tree, 1, 0, n - 1, b - 1, diff);
            v[b - 1] = c;
        }
        else {
            if (b>c) {
                cout << query(tree, 1, 0, n - 1, c - 1, b - 1) << endl;
            }
            else {
                cout << query(tree, 1, 0, n - 1, b - 1, c - 1) << endl;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}