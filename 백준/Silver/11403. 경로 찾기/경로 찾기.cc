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

int n;

void dfs(matrix& mat, vector<ll>& visit, int now) {
    FOR(next, 0, n) {
        if (mat[now][next] && !visit[next]) {
            visit[next] = 1;
            dfs(mat, visit, next);
        }
    }
}

void solve() {
    
    cin >> n;
    matrix mat(n, vector<ll>(n));

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cin >> mat[i][j];
        }
    }

    matrix visit_mat(n, vector<ll>(n, 0));

    FOR(start, 0, n) {
        dfs(mat, visit_mat[start], start);
    }

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cout << visit_mat[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}