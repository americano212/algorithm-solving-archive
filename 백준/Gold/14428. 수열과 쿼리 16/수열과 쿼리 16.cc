#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pllp pair<ll, pll>
#define pff pair<float, float>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
#define all(v) v.begin(), v.end()
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

struct EDGE {
    ll start;
    ll end;
    ll cost;
};

//struct CMP {
//    bool operator() (INFO a, INFO b) {
//        return a.cost > b.cost;
//    }
//};

pll init(vector<ll>& v, vector<pll>& tree, int node, int start, int end) {
    if (start == end) return tree[node] = { v[start], start + 1 };
    int mid = (start + end) / 2;
    pll a = init(v, tree, 2 * node, start, mid);
    pll b = init(v, tree, 2 * node + 1, mid + 1, end);
    if (a.first == b.first) {
        return tree[node] = (a.second < b.second) ? a : b;
    }
    else {
        return tree[node] = (a.first < b.first) ? a : b;
    }
}

pll query(vector<pll>& tree, int node, int start, int end, int left, int right) {
    if (right < start || end < left) return { INF, INF };
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    pll a = query(tree, 2 * node, start, mid, left, right);
    pll b = query(tree, 2 * node + 1, mid + 1, end, left, right);
    if (a.first == b.first) {
        return (a.second <= b.second) ? a : b;
    }
    else {
        return (a.first < b.first) ? a : b;
    }
}

void update(vector<pll>& tree, int node, int start, int end, int index, int value) {
    if (index < start || end < index) return;
    if (start == end && start == index) {
        tree[node] = { value, index + 1 };
        return;
    }
    int mid = (start + end) / 2;
    update(tree, 2 * node, start, mid, index, value);
    update(tree, 2 * node + 1, mid + 1, end, index, value);
    pll a = tree[2 * node];
    pll b = tree[2 * node + 1];
    if (a.first == b.first) {
        tree[node] = (a.second <= b.second) ? a : b;
    }
    else {
        tree[node] = (a.first < b.first) ? a : b;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    FOR(i, 0, n) {
        cin >> v[i];
    }
    vector<pll> tree(4 * n);
    int m;
    cin >> m;

    init(v, tree, 1, 0, n - 1);

    ll a, b, c;
    FOR(i, 0, m) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(tree, 1, 0, n - 1, b - 1, c);
        }
        else {
            cout << query(tree, 1, 0, n - 1, b - 1, c - 1).second << endl;
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