#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pllp pair<ll, pll>
#define pff pair<float, float>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
#define all(v) v.begin(), v.end()
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

double dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
double dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

int n, m;
void dfs(matrix& mat, vector<ll>& visit, int now) {
    FOR(next, 1, n + 1) {
        if (mat[now][next] && !visit[next]) {
            visit[next] = 1;
            dfs(mat, visit, next);
        }
    }
}

void solve() {
    
    cin >> n >> m;
    matrix shorter(n + 1, vector<ll>(n + 1, 0));
    matrix longer(n + 1, vector<ll>(n + 1, 0));
    int a, b;
    FOR(_, 0, m) {
        cin >> a >> b;
        shorter[a][b] = 1;
        longer[b][a] = 1;
    }

    matrix visit_mat(n + 1, vector<ll>(n + 1, 0));

    FOR(start, 1, n + 1) {
        visit_mat[start][start] = 1;
        dfs(shorter, visit_mat[start], start);
        dfs(longer, visit_mat[start], start);
    }

    int ans = 0;
    FOR(i, 1, n + 1) {
        int temp = 0;
        FOR(j, 1, n + 1) {
            temp += visit_mat[i][j];
        }
        if (temp == n) ans++;
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