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
    vector<string> v(n);
    FOR(i, 0, n) {
        cin >> v[i];
    }
    
    matrix mat(n, vector<ll>(m, 0));

    queue<pll> qu;
    qu.push(make_pair(0, 0));
    mat[0][0] = 1;

    while (!qu.empty()) {
        int now_x = qu.front().first;
        int now_y = qu.front().second;
        qu.pop();
        FOR(i, 0, 4) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];
            if (0 <= next_x && next_x < n && 0 <= next_y && next_y < m) {
                if (v[next_x][next_y] == '1' && mat[next_x][next_y] == 0) {
                    mat[next_x][next_y] = mat[now_x][now_y] + 1;
                    qu.push(make_pair(next_x, next_y));
                }
            }
        }
    }

    //FOR(i, 0, n) {
    //    FOR(j, 0, m) {
    //        cout << mat[i][j] << ' ';
    //    }
    //    cout << endl;
    //}

    cout << mat[n - 1][m - 1] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();

    return 0;
}