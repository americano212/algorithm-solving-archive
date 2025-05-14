#include <bits/stdc++.h>
#define FOR(x, y, n) for (int x = y; x < (n); x++)
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
#define lcm(a, b) a *b / gcd(a, b)
#define all(v) v.begin(), v.end()
#define btw(x, a, b) a <= x &&x < b
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 10007LL;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int dx6[6] = {1, -1, 0, 0, 0, 0};
int dy6[6] = {0, 0, 1, -1, 0, 0};
int dz6[6] = {0, 0, 0, 0, 1, -1};
int dx8[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy8[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<vector<int>> visit(n, vector<int>(m, 0));

    FOR(i, 0, n) { cin >> v[i]; }
    queue<pii> qu;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (v[i][j] == 'I') {
                qu.push({i, j});
                visit[i][j] = 1;
            }
        }
    }

    int ans = 0;
    while (!qu.empty()) {
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();
        if (v[x][y] == 'P')
            ans++;

        FOR(idx, 0, 4) {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            if (btw(nx, 0, n) && btw(ny, 0, m)) {
                if (visit[nx][ny] == 0 && v[nx][ny] != 'X') {
                    visit[nx][ny] = 1;
                    qu.push({nx, ny});
                }
            }
        }
    }
    if (ans) {
        cout << ans << endl;
    } else {
        cout << "TT" << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)
        solve();

    return 0;
}
