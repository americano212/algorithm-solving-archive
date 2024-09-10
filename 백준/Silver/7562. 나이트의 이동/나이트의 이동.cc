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
    int sx, sy, ex, ey;
    cin >> sx >> sy;
    cin >> ex >> ey;

    int dxn8[8] = { 2,1,-2,-1,2,1,-2,-1 };
    int dyn8[8] = { 1,2,1,2,-1,-2,-1,-2 };

    queue<pllp> qu;
    qu.push({ 0,{sx,sy} });

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[sx][sy] = true;

    while (!qu.empty()) {
        int x = qu.front().second.first;
        int y = qu.front().second.second;
        int depth = qu.front().first;
        qu.pop();

        if (x == ex && y == ey) {
            cout << depth << endl;
            return;
        }

        FOR(idx, 0, 8) {
            int nx = x + dxn8[idx];
            int ny = y + dyn8[idx];
            if (btw(nx, 0, n) && btw(ny, 0, n)) {
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    qu.push({ depth + 1,{nx,ny} });
                }
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