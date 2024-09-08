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


void solve() {
    int n;
    cin >> n;
    
    vector<int> parent(n + 1, -1);
    
    matrix mat(n + 1);
    int a, b;
    FOR(_, 0, n - 1) {
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
        parent[b] = a;
    }
    int root = 0;
    FOR(i, 1, n + 1) {
        if (parent[i] == -1) {
            root = i;
        }
    }
    // cout << root << endl;

    vector<int> depth(n + 1, 0);
    queue<pii> qu;
    qu.push({ root, 1 });
    depth[root] = 1;

    while (!qu.empty()) {
        int now_node = qu.front().first;
        int now_depth = qu.front().second;
        qu.pop();

        FOR(idx, 0, mat[now_node].size()) {
            int next_node = mat[now_node][idx];
            if (next_node != parent[now_node]) {
                depth[next_node] = now_depth + 1;
                qu.push({ next_node, now_depth + 1 });
            }
        }
    }

    //FOR(i, 1, n + 1) {
    //    cout << depth[i] << ' ';
    //}
    //cout << endl;

    cin >> a >> b;
    while (1) {
        if (depth[a] > depth[b]) {
            a = parent[a];
        }
        else if (depth[a] < depth[b]) {
            b = parent[b];
        }
        else {
            if (a == b) {
                cout << a << endl;
                break;
            }
            else {
                a = parent[a];
                b = parent[b];
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    cin >> tc;
    while (tc--)solve();

    return 0;
}