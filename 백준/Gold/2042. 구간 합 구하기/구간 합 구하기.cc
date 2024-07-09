#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2147483647
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

ll init(vector<ll>& v, vector<ll>& tree, int node, int start, int end) {
    if (start == end) return tree[node] = v[start];
    int mid = (start + end) / 2;
    return tree[node] = init(v, tree, node * 2, start, mid) + init(v, tree, node * 2 + 1, mid + 1, end);
}

ll sum(vector<ll>& tree, int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

void update(vector<ll>& tree, int node, int start, int end, int idx, ll diff) {
    if (idx < start || end < idx) return;
    tree[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, idx, diff);
        update(tree, node * 2 + 1, mid + 1, end, idx, diff);
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> v(n);
    FOR(i, 0, n) {
        cin >> v[i];
    }
    vector<ll> tree(4 * n, 0);
    
    init(v, tree, 1, 0, n - 1);

    //FOR(i, 0, 4 * n) {
    //    cout << tree[i] << ' ';
    //}
    //cout << endl;

    ll flag, a, b;
    FOR(_, 0, m + k) {
        cin >> flag >> a >> b;
        if (flag == 1) {
            ll diff = b - v[a - 1];
            v[a - 1] = b;
            update(tree, 1, 0, n - 1, a - 1, diff);
        }

        //FOR(i, 0, 4 * n) {
        //    cout << tree[i] << ' ';
        //}
        //cout << endl;

        if (flag == 2) {
            cout << sum(tree, 1, 0, n - 1, a - 1, b - 1) << endl;
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