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
    int u, v;
    cin >> n >> m;
    vector<bool> visit(n + 1, false);

    matrix mat(n + 1, vector<ll>(n + 1, 0));

    FOR(i, 0, m) {
        cin >> u >> v;
        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    int ans = 0;

    queue<int> qu;
    FOR(start, 1, n + 1) {
        if (visit[start]) continue;

        qu.push(start);
        visit[start] = true;
        while (!qu.empty()) {
            int now = qu.front();
            qu.pop();

            FOR(next, 1, n + 1) {
                if (!visit[next] && mat[now][next]) {
                    qu.push(next);
                    visit[next] = true;
                }
            }
        }
        //FOR(i, 0, n + 1) {
        //    cout << visit[i] << ' ';
        //}
        //cout << endl;
        ans++;
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