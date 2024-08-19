#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pllp pair<ll, pll>
#define pff pair<float, float>
#define pdd pair<double, double>
#define pldd pair<ld, ld>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
#define all(v) v.begin(), v.end()
#define btw(x,a,b) a<=x && x<b
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int dx6[6] = { 1,-1,0,0,0,0 };
int dy6[6] = { 0,0,1,-1,0,0 };
int dz6[6] = { 0,0,0,0,1,-1 };
int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

struct EDGE { ll start; ll end; ll cost; };
struct DOT3 { ll x; ll y; ll z; };
struct NODE { int x; int y; int dir; };
struct ITEM { bool isNum; int num = 0; char bracket = ' '; };

ll init(vector<ll>& tree, vector<int>& v, int node, int start, int end) {
    if (start == end) return tree[node] = v[start];

    int mid = (start + end) / 2;
    ll a = init(tree, v, 2 * node, start, mid);
    ll b = init(tree, v, 2 * node + 1, mid + 1, end);
    return tree[node] = min(a, b);
}

ll query(vector<ll>& tree, int node, int start, int end, int left, int right) {
    if (right < start || end < left) return INF;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    ll a = query(tree, 2 * node, start, mid, left, right);
    ll b = query(tree, 2 * node + 1, mid + 1, end, left, right);
    return min(a, b);
}

void update(vector<ll>& tree, vector<int>& v, int node, int start, int end, int index) {
    if (index < start || end < index) return;
    if (start == end) {
        tree[node] = v[start];
        return;
    }

    int mid = (start + end) / 2;
    update(tree, v, 2 * node, start, mid, index);
    update(tree, v, 2 * node + 1, mid + 1, end, index);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    FOR(i, 0, n) {
        cin >> v[i];
    }

    vector<ll> tree(4 * n, 0);
    init(tree, v, 1, 0, n - 1);

    
    int q;
    cin >> q;
    int a, b, c;
    FOR(_, 0, q) {
        cin >> a >> b >> c;
        if (a == 2) {
            cout << query(tree, 1, 0, n - 1, b - 1, c - 1) << endl;
        }
        if (a == 1) {
            v[b - 1] = c;
            update(tree, v, 1, 0, n - 1, b - 1);
            
        }
        //FOR(i, 0, 4*n) {
        //    cout << tree[i] << ' ';
        //}
        //cout << endl;

    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}