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
struct NODE { ll max_value; int max_index; ll now_value; int now_node; };
struct ITEM { bool isNum; int num = 0; char bracket = ' '; };
struct MOVE { int x; int y; int time; };

void solve() {
    ll n, s;
    cin >> n >> s;
    vector<pll> v(n);
    ll h, c;
    FOR(i, 0, n) {
        cin >> h >> c;
        v[i] = { h,c };
    }
    sort(all(v));

    vector<ll> height(n);
    vector<ll> cost(n);
    FOR(i, 0, n) {
        height[i] = v[i].first;
        cost[i] = v[i].second;
    }
    //FOR(i, 0, n) {
    //    cout << height[i] << ' ';
    //}
    //cout << endl;
    //FOR(i, 0, n) {
    //    cout << cost[i] << ' ';
    //}
    //cout << endl;

    vector<vector<ll>> dp(2, vector<ll>(n, 0));
    if (height[0] >= s) dp[0][0] = cost[0];

    FOR(i, 1, n) {
        dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
        
        ll k = upper_bound(all(height), height[i] - s) - height.begin();
        // cout << k << ' ' << height[i] - s << endl;
        
        if (k == 0) {
            if (height[i] >= s) dp[0][i] = cost[i];
        }
        else {
            dp[0][i] = max(dp[0][k - 1], dp[1][k - 1]) + cost[i];
        }
        
    }

    //FOR(i, 0, n) {
    //    cout << dp[0][i] << ' ';
    //}
    //cout << endl;
    //FOR(i, 0, n) {
    //    cout << dp[1][i] << ' ';
    //}
    //cout << endl;
    cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}