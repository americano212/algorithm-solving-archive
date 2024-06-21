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
    int n, m;
    cin >> n >> m;
    matrix mat(m, vector<ll>(n, 0));

    queue<pair<pll, int>> qu;
    bool hasZero = false;

    FOR(i, 0, m) {
        FOR(j, 0, n) {
            cin >> mat[i][j];
            if (mat[i][j] == 0) hasZero = true;
            if (mat[i][j] == 1) qu.push(make_pair(make_pair(i, j), 1));
        }
    }
    if (!hasZero) {
        cout << 0 << endl;
        return;
    }

    while (!qu.empty()) {
        int x = qu.front().first.first;
        int y = qu.front().first.second;
        int cost = qu.front().second;
        qu.pop();

        FOR(i, 0, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                if (mat[nx][ny] == 0) {
                    mat[nx][ny] = cost;
                    qu.push(make_pair(make_pair(nx, ny), cost + 1));
                }
            }
        }
    }
    ll ans = -1;
    FOR(i, 0, m) {
        FOR(j, 0, n) {
            if (mat[i][j] == 0) {
                cout << -1 << endl;
                return;
            }
            ans = max(ans, mat[i][j]);
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();

    return 0;
}