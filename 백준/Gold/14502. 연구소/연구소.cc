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
struct COORDINATE { ll x; ll y; ll z; };
struct NODE { int x; int y; int dir; };

struct ITEM { bool isNum; int num = 0; char bracket = ' '; };

void solve() {
    int n, m;
    cin >> n >> m;
    matrix mat(n, vector<ll>(m));

    vector<pii> zero;
    queue<pii> start;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> mat[i][j];
            if (mat[i][j] == 0) zero.push_back({ i,j });
            if (mat[i][j] == 2) start.push({ i,j });
        }
    }
    ll zero_cnt = zero.size();
    int two_cnt = start.size();

    ll ans = 0;

    FOR(i, 0, zero.size()) {
        FOR(j, i + 1, zero.size()) {
            FOR(k, j + 1, zero.size()) {
                if (i == j || j == k || k == i) continue;

                mat[zero[i].first][zero[i].second] = 1;
                mat[zero[j].first][zero[j].second] = 1;
                mat[zero[k].first][zero[k].second] = 1;

                queue<pii> qu = start;
                vector<vector<bool>> visit(n, vector <bool>(m, false));
                int temp = 0;
                while (!qu.empty()) {
                    int x = qu.front().first;
                    int y = qu.front().second;
                    visit[x][y] = true;
                    qu.pop();

                    FOR(idx, 0, 4) {
                        int nx = x + dx[idx];
                        int ny = y + dy[idx];
                        if (btw(nx, 0, n) && btw(ny, 0, m)) {
                            if (mat[nx][ny] == 0 && visit[nx][ny] == false) {
                                temp++;
                                visit[nx][ny] = true;
                                qu.push({ nx,ny });
                            }
                        }
                    }
                }
                ans = max(ans, zero_cnt - temp - 3);
                mat[zero[i].first][zero[i].second] = 0;
                mat[zero[j].first][zero[j].second] = 0;
                mat[zero[k].first][zero[k].second] = 0;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}