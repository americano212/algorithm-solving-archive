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

int n, m;

void fillAir(matrix& mat) {
    queue<pii> qu;
    qu.push({ 0,0 });

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[0][0] = true;

    while (!qu.empty()) {
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();

        FOR(idx, 0, 4) {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            if (btw(nx, 0, n) && btw(ny, 0, m)) {
                if (mat[nx][ny] != 1 && visited[nx][ny] == false) {
                    mat[nx][ny] = 2;
                    visited[nx][ny] = true;
                    qu.push({ nx,ny });
                }
            }
        }
    }
}

void solve() {
    
    cin >> n >> m;
    matrix mat(n, vector<ll>(m, 0));

    ll cheese = 0;

    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> mat[i][j];
            if (mat[i][j] == 1) cheese++;
        }
    }

    ll timer = 0;
    while (1) {
        if (cheese == 0) break;

        fillAir(mat);

        FOR(i, 0, n) {
            FOR(j, 0, m) {
                int check = 0;
                if (mat[i][j] == 1) {
                    FOR(idx, 0, 4) {
                        int ni = i + dx[idx];
                        int nj = j + dy[idx];
                        if (btw(ni, 0, n) && btw(nj, 0, m)) {
                            if (mat[ni][nj] == 2) check++;
                        }
                    }
                }
                if (check >= 2) {
                    mat[i][j] = 0;
                    cheese--;
                }
            }
        }

        timer++;
    }
    cout << timer << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}