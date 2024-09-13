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

const ll mod = 1'000'000'000LL;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
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
struct MOVE { int x; int y; int time; };

pii init(vector<int>& v, vector<pii>& tree, int node, int start, int end) {
    if (start == end) {
        if (v[start] % 2 == 0) return tree[node] = { 0,1 };
        else return tree[node] = { 1,0 };
    }
    int mid = (start + end) / 2;
    pii a = init(v, tree, 2 * node, start, mid);
    pii b = init(v, tree, 2 * node + 1, mid + 1, end);
    return tree[node] = { a.first + b.first, a.second + b.second };
}

pii query(vector<pii>& tree, int node, int start, int end, int left, int right) {
    if (right < start || end < left) return { 0,0 };
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    pii a = query(tree, 2 * node, start, mid, left, right);
    pii b = query(tree, 2 * node + 1, mid + 1, end, left, right);
    return { a.first + b.first, a.second + b.second };
}

void update(vector<int>& v, vector<pii>& tree, int node, int start, int end, int index) {
    if (index < start || end < index) return;
    if (start == end) {
        if (v[start] % 2 == 0) tree[node] = { 0,1 };
        else tree[node] = { 1,0 };
        return;
    }
    int mid = (start + end) / 2;
    update(v, tree, 2 * node, start, mid, index);
    update(v, tree, 2 * node + 1, mid + 1, end, index);
    tree[node] = { tree[2 * node].first + tree[2 * node + 1].first, tree[2 * node].second + tree[2 * node + 1].second };
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    FOR(i, 0, n) cin >> v[i];

    vector<pii> tree(4 * n); // {홀,찍}
    init(v, tree, 1, 0, n - 1);

    //FOR(i, 1, 15) {
    //    cout << tree[i].first << ' ' << tree[i].second << endl;
    //}
    //cout << endl;

    int m;
    cin >> m;
    int flag, a, b;
    FOR(_, 0, m) {
        cin >> flag >> a >> b;
        if (flag == 2) {
            cout << query(tree, 1, 0, n - 1, a - 1, b - 1).second << endl;
        }
        else if (flag == 3) {
            cout << query(tree, 1, 0, n - 1, a - 1, b - 1).first << endl;
        }
        else {
            v[a - 1] = b;
            update(v, tree, 1, 0, n - 1, a - 1);
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