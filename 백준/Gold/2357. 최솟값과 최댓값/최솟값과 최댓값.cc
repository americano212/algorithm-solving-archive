#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define pll pair<ll, ll>
#define matrix vector<vector<ll>>
#define lcm(a, b) a *b / gcd(a, b)
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1000000007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

pll init(vector<ll>& v, vector<pll>& tree, int node, int start, int end) {
    if (start == end) {
        tree[node].first = v[start];
        tree[node].second = v[start];
        return tree[node];
    }
    int mid = (start + end) / 2;
    pll l = init(v, tree, 2 * node, start, mid);
    pll r = init(v, tree, 2 * node + 1, mid + 1, end);
    return tree[node] = { max(l.first,r.first), min(l.second,r.second) };
}

pll max_min(vector<pll>& tree, int node, int start, int end, int left, int right) {
    if (right < start || end < left) return make_pair(0, INF);
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    pll l = max_min(tree, 2 * node, start, mid, left, right);
    pll r = max_min(tree, 2 * node + 1, mid + 1, end, left, right);
    return { max(l.first,r.first), min(l.second,r.second) };
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> v(n);
    vector<pll> tree(4 * n); // pll(최대, 최소)
    FOR(i, 0, n) {
        cin >> v[i];
    }

    init(v, tree, 1, 0, n - 1);

    int a, b;
    FOR(_, 0, m) {
        cin >> a >> b;
        pll result = max_min(tree, 1, 0, n - 1, a - 1, b - 1);
        cout << result.second << ' ' << result.first << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}