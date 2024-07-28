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
int r, c;
vector<string> v(20);

void dfs(int x, int y, int depth, vector<bool>& check) {
    ans = max(ans, depth);

    FOR(i, 0, 4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (btw(nx, 0, r) && btw(ny, 0, c)) {
            if (check[v[nx][ny] - 'A'] == false) {
                check[v[nx][ny] - 'A'] = true;
                dfs(nx, ny, depth + 1, check);
                check[v[nx][ny] - 'A'] = false;
            }
        }
    }
}

void solve() {
    
    cin >> r >> c;

    FOR(i, 0, r) {
        cin >> v[i];
    }

    vector<bool> check(26, false);
    check[v[0][0] - 'A'] = true;
    dfs(0, 0, 1, check);
    cout << ans << endl;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    //cin >> tc;
    while (tc--)solve();

    return 0;
}