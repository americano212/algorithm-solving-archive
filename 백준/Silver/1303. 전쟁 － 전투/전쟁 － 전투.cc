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

ll bfs(vector<string>& mat, vector<vector<bool>>& visited, int x, int y) {
    queue<pii> qu;
    qu.push({ x,y });
    ll result = 0;
    while (!qu.empty()) {
        pii now = qu.front();
        qu.pop();
        result++;

        FOR(idx, 0, 4) {
            int nx = now.first + dx[idx];
            int ny = now.second + dy[idx];
            if (btw(nx, 0, n) && btw(ny, 0, m)) {
                if (mat[now.first][now.second] == mat[nx][ny] && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    qu.push({ nx,ny });
                }
            }
        }
    }
    return result;
}

void solve() {
    cin >> m >> n;
    vector<string> mat(n);
    FOR(i, 0, n) cin >> mat[i];

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    ll ans_w = 0, ans_b = 0;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (visited[i][j]) continue;
            visited[i][j] = true;
            ll result = bfs(mat, visited, i, j);
            if (mat[i][j] == 'W') ans_w += result * result;
            else ans_b += result * result;
        }
    }
    cout << ans_w << ' ' << ans_b << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}