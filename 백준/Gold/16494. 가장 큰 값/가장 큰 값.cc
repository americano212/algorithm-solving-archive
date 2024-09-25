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
struct NODE { int a; int b; int c; };
struct ITEM { bool isNum; int num = 0; char bracket = ' '; };
struct MOVE { int x; int y; int time; };

int n, m;

int ans = -INF;

void dfs(vector<int>& v, vector<bool>& visited, int now_idx, int sum) {
    if (now_idx == n) {
        int min_group = 0;
        int max_group = 0;
        bool check = false;
        FOR(i, 0, n) {
            if (check == false && visited[i] == true) min_group++;
            if (visited[i] == true) max_group++;
            check = visited[i];
        }
        if (btw(m, min_group, max_group + 1)) {
            ans = max(ans, sum);
        }
        return;
    }

    // 지금꺼 방문
    visited[now_idx] = true;
    dfs(v, visited, now_idx + 1, sum + v[now_idx]);
    // 지금꺼 안 방문
    visited[now_idx] = false;
    dfs(v, visited, now_idx + 1, sum);
}

void solve() {
    cin >> n >> m;
    vector<int> v(n);
    FOR(i, 0, n) cin >> v[i];

    vector<bool> visited(n, false);

    dfs(v, visited, 0, 0);

    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}