#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2147483647
#define ll long long
#define pll pair<ll, ll>
#define matrix vector<vector<ll>>
#define lcm(a, b) a *b / gcd(a, b)
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1000000007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}



void solve() {
    int m, n, k;
    cin >> m >> n >> k;

    matrix mat(n, vector<ll>(m, 0));

    int x, y;
    FOR(i, 0, k) {
        cin >> x >> y;
        mat[y][x] = 1;
    }
    queue<pll> qu;

    int ans = 0;

    FOR(i, 0, n) {
        FOR(j, 0, m) {
            int start = mat[i][j];
            if (!start) continue;

            ans++;
            qu.push(make_pair(i, j));

            while (!qu.empty()) {
                int nx, ny;
                nx = qu.front().first;
                ny = qu.front().second;
                qu.pop();

                FOR(idx, 0, 4) {
                    int next_x = nx + dx[idx];
                    int next_y = ny + dy[idx];
                    if (0 <= next_x && next_x < n && 0 <= next_y && next_y < m) {
                        if (mat[next_x][next_y]) {
                            qu.push(make_pair(next_x, next_y));
                            mat[next_x][next_y] = 0;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    cin >> tc;
    while (tc--) solve();

    return 0;
}