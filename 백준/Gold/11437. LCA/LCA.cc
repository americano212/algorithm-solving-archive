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

int lca(vector<int>& parent, vector<int>& depth, int a, int b) {
    while (1) {
        if (depth[a] > depth[b]) {
            a = parent[a];
        }
        else if (depth[a] < depth[b]) {
            b = parent[b];
        }
        else {
            if (a == b) return a;
            a = parent[a];
            b = parent[b];
        }
    }
}

void solve() {
    int n;
    cin >> n;
    matrix mat(n + 1);

    int a, b;
    FOR(_, 0, n - 1) {
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    vector<int> parent(n + 1, -1);
    vector<int> depth(n + 1, -1);
    depth[1] = 1;

    queue<pii> qu;
    qu.push({ 1, 1 });
    while (!qu.empty()) {
        int now_node = qu.front().first;
        int now_depth = qu.front().second;
        qu.pop();

        FOR(idx, 0, mat[now_node].size()) {
            int next_node = mat[now_node][idx];
            if (next_node != parent[now_node]) {
                parent[next_node] = now_node;
                depth[next_node] = now_depth + 1;
                qu.push({ next_node, now_depth + 1 });
            }
        }
    }
    parent[1] = 0;

    //FOR(i, 1, n + 1) {
    //    cout << parent[i] << ' ';
    //}
    //cout << endl;

    //FOR(i, 1, n + 1) {
    //    cout << depth[i] << ' ';
    //}
    //cout << endl;

    int m;
    cin >> m;
    FOR(_, 0, m) {
        cin >> a >> b;
        cout << lca(parent, depth, a, b) << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}