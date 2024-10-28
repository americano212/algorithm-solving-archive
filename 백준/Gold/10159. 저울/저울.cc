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

const ll mod = 10'007LL;
int dx[4] = { 1,0,-1,0 };
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


void solve() {
    int n, m;
    cin >> n >> m;
    matrix mat_a(n + 1, vector<ll>(n + 1, INF)), mat_b(n + 1, vector<ll>(n + 1, INF));

    int a, b;
    FOR(_, 0, m) {
        cin >> a >> b;
        mat_a[a][b] = 1;
        mat_b[b][a] = 1;
    }

    

    FOR(i, 1, n + 1) {
        mat_a[i][i] = 0;
        mat_b[i][i] = 0;
    }

    FOR(k, 1, n + 1) {
        FOR(i, 1, n + 1) {
            FOR(j, 1, n + 1) {
                mat_a[i][j] = min(mat_a[i][j], mat_a[i][k] + mat_a[k][j]);
                mat_b[i][j] = min(mat_b[i][j], mat_b[i][k] + mat_b[k][j]);
            }
        }
    }

    vector<int> ans(n + 1, -1);

    FOR(i, 1, n + 1) {
        FOR(j, 1, n + 1) {
            if (mat_a[i][j] != INF) ans[i]++;
            if (mat_b[i][j] != INF) ans[i]++;
        }
    }
    
    FOR(i, 1, n + 1) {
        cout << n - ans[i] << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}