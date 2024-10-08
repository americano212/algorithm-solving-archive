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
    int n;
    cin >> n;
    vector<int> time(n);
    
    vector<int> cost(n);
    FOR(i, 0, n) cin >> time[i] >> cost[i];

    vector<pii> dp(n, { 0,0 }); // 지금 상담할 때, 안할 때
    if (n >= time[0]) {
        dp[0].first = cost[0];
    }
    
    
    FOR(i, 1, n) {
        if (n - i >= time[i]) {
            FOR(j, 0, i) {
                if (i - j >= time[j]) {
                    dp[i].first = max(dp[i].first, dp[j].first);
                }
            }
            dp[i].first += cost[i];
        }
        dp[i].second = max(dp[i - 1].first, dp[i - 1].second);
    }

    //FOR(i, 0, n) {
    //    cout << dp[i].first << ' ';
    //}
    //cout << endl;
    //FOR(i, 0, n) {
    //    cout << dp[i].second << ' ';
    //}
    //cout << endl;

    cout << max(dp[n - 1].first, dp[n - 1].second) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}