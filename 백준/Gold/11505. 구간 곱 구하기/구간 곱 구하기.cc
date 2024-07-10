#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define pll pair<ll, ll>
#define matrix vector<vector<ll>>
#define lcm(a, b) a *b / gcd(a, b)
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

ll init(vector<int>& v, vector<ll>& tree, int node, int start, int end) {
    if (start == end) return tree[node] = v[start];
    int mid = (start + end) / 2;

    return tree[node] = init(v, tree, 2 * node, start, mid) * init(v, tree, 2 * node + 1, mid + 1, end) % mod;
}

ll mult(vector<ll>& tree, int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 1;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return mult(tree, 2 * node, start, mid, left, right) * mult(tree, 2 * node + 1, mid + 1, end, left, right) % mod;
}

void update(vector<ll>& tree, int node, int start, int end, int index, ll value) {
    // cout << "??" << node << ' ' << start << ' ' << end << ' ' << index << ' ' << before << ' ' << now << endl;
    if (index < start || end < index) return;
    if (start == end) {
        tree[node] = value;
        return;
    }

    int mid = (start + end) / 2;
    update(tree, 2 * node, start, mid, index, value);
    update(tree, 2 * node + 1, mid + 1, end, index, value);
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % mod;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    vector<ll> tree(4 * n);

    FOR(i, 0, n) {
        cin >> v[i];
    }

    init(v, tree, 1, 0, n - 1);

    //FOR(i, 0, 4 * n) {
    //    cout << tree[i] << ' ';
    //}
    //cout << endl;

    int a, b, c;
    FOR(_, 0, m + k) {
        cin >> a >> b >> c;
        if (a == 1) update(tree, 1, 0, n - 1, b - 1, c);

        if (a == 2) {
            cout << mult(tree, 1, 0, n - 1, b - 1, c - 1) % mod << endl;
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