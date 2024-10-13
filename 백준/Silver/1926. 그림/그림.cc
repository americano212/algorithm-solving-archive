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

int max_size = 0;
int n, m;

void bfs(matrix& mat, matrix& visited, int sx, int sy) {
    int size = 0;
    queue<pii> qu;
    qu.push({ sx,sy });

    while (!qu.empty()) {
        pii now = qu.front();
        qu.pop();

        size++;

        FOR(idx, 0, 4) {
            int nx = now.first + dx[idx];
            int ny = now.second + dy[idx];
            if (btw(nx, 0, n) && btw(ny, 0, m)) {
                if (mat[nx][ny] == 1 && visited[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    qu.push({ nx,ny });
                }
            }
        }
    }
    max_size = max(max_size, size);
}


void solve() {
    cin >> n >> m;
    matrix mat(n, vector<ll>(m));
    matrix visited(n, vector<ll>(m, 0));
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> mat[i][j];
        }
    }

    int cnt = 0;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (mat[i][j] == 1 && visited[i][j] == 0) {
                visited[i][j] = 1;
                cnt++;
                bfs(mat, visited, i, j);
            }
        }
    }
    cout << cnt << endl;
    cout << max_size << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}