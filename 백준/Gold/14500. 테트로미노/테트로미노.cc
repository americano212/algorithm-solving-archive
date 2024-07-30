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
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dx6[6] = { 1,-1,0,0,0,0 };
int dy6[6] = { 0,0,1,-1,0,0 };
int dz6[6] = { 0,0,0,0,1,-1 };
int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

struct EDGE { ll start; ll end; ll cost; };
struct COORDINATE { ll x; ll y; ll z; };

int ans = 0;
int n, m;

matrix mat(500, vector<ll>(500, 0));

void dfs(int x, int y, int depth, int sum, vector<vector<bool>>& visit) {
    if (depth == 4) {
        ans = max(ans, sum);
        return;
    }

    FOR(idx, 0, 4) {
        int nx = x + dx[idx];
        int ny = y + dy[idx];
        if (btw(nx, 0, n) && btw(ny, 0, m)) {
            if (!visit[nx][ny]) {
                visit[nx][ny] = true;
                dfs(nx, ny, depth + 1, sum + mat[nx][ny], visit);
                visit[nx][ny] = false;
            }
        }
    }
}

void solve() {
    
    cin >> n >> m;
    
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> mat[i][j];
        }
    }
    vector<vector<bool>> visit(500, vector<bool>(500, false));
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            visit[i][j] = true;
            dfs(i, j, 1, mat[i][j], visit);
            visit[i][j] = false;
        }
    }

    // ㅜ 모양 고려
    int temp;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (btw(i + 1, 0, n) && btw(j + 2, 0, m)) {
                temp = mat[i][j] + mat[i][j + 1] + mat[i][j + 2] + mat[i + 1][j + 1];
                ans = max(ans, temp);
            }

            if (btw(i - 1, 0, n) && btw(j + 2, 0, m)) {
                temp = mat[i][j] + mat[i][j + 1] + mat[i][j + 2] + mat[i - 1][j + 1];
                ans = max(ans, temp);
            }

            if (btw(i + 2, 0, n) && btw(j + 1, 0, m)) {
                temp = mat[i][j] + mat[i + 1][j] + mat[i + 2][j] + mat[i + 1][j + 1];
                ans = max(ans, temp);
            }

            if (btw(i + 2, 0, n) && btw(j - 1, 0, m)) {
                temp = mat[i][j] + mat[i + 1][j] + mat[i + 2][j] + mat[i + 1][j - 1];
                ans = max(ans, temp);
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