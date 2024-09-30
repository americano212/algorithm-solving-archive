#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647LL
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
int dy[4] = { 0,-1,0,1 };
int dx6[6] = { 1,-1,0,0,0,0 };
int dy6[6] = { 0,0,1,-1,0,0 };
int dz6[6] = { 0,0,0,0,1,-1 };
int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

struct EDGE { ll start; ll end; ll cost; };
struct DOT3 { ll x; ll y; ll z; };
struct NODE { ll max_value; int max_index; ll now_value; int now_node; };
struct ITEM { bool isNum; int num = 0; char bracket = ' '; };
struct MOVE { int x; int y; int time; };

int n, m;
bool result = false;

void dfs(matrix& mat, vector<bool>& visited, int node, int depth) {
    if (depth == 5) {
        result = true;
        return;
    }

    FOR(idx, 0, mat[node].size()) {
        int next = mat[node][idx];
        if (!visited[next]) {
            visited[next] = true;
            dfs(mat, visited, next, depth + 1);
            visited[next] = false;
        }
    }
}

void solve() {
    cin >> n >> m;
    matrix mat(n);
    int a, b;
    FOR(_, 0, m) {
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    vector<bool> visited;
    FOR(start, 0, n) {
        visited.assign(n, false);
        visited[start] = true;
        dfs(mat, visited, start, 1);
        if (result) {
            cout << 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}