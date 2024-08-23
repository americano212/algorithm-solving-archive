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


void solve() {
    ll m, n;
    cin >> m >> n;
    
    ll cost;
    matrix mat(m, vector<ll>(n));
    priority_queue<pllp, vector<pllp>, greater<pllp>> pq;

    FOR(i, 0, m) {
        FOR(j, 0, n) {
            cin >> cost;
            mat[i][j] = cost;

            if (i == m - 1 && j == n - 1) continue;
            pq.push({ cost, {i,j} });
        }
    }
    matrix dp(m, vector<ll>(n, 0));
    dp[m - 1][n - 1] = 1;
    

    while (!pq.empty()) {
        pllp now = pq.top();
        // cout << now.first << endl;
        ll x = now.second.first;
        ll y = now.second.second;
        pq.pop();
        FOR(idx, 0, 4) {
            ll nx = x + dx[idx];
            ll ny = y + dy[idx];
            if (btw(nx, 0, m) && btw(ny, 0, n)) {
                if (mat[x][y] > mat[nx][ny]) {
                    dp[x][y] += dp[nx][ny];
                }
            }
        }
    }

    /*FOR(i, 0, m) {
        FOR(j, 0, n) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }*/
    cout << dp[0][0] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}