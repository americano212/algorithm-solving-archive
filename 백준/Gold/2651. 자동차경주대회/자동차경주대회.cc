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

const ll mod = 1'000'000'000LL;
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
struct NODE { int x; int y; int dir; };
struct ITEM { bool isNum; int num = 0; char bracket = ' '; };
struct MOVE { int x; int y; int time; };


void solve() {
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<ll> distance(n + 2, 0);
    int temp;
    FOR(i, 1, n + 2) {
        cin >> temp;
        distance[i] = distance[i - 1] + temp;
    }
    //FOR(i, 0, n + 2) {
    //    cout << distance[i] << ' ';
    //}
    //cout << endl;
    vector<ll> cost(n + 1, 0);
    FOR(i, 1, n + 1) {
        cin >> cost[i];
    }
    vector<ll> dp(n + 1, INF * INF);
    vector<ll> dp_log(n + 1, -1);

    dp[0] = 0;
    FOR(i, 1, n + 1) {
        FOR(j, 0, i) {
            if (distance[i] - distance[j] > k) continue;
            if (dp[i] > dp[j] + cost[i]) {
                dp[i] = dp[j] + cost[i];
                dp_log[i] = j;
            }
        }
    }
    //FOR(i, 0, n + 1) {
    //    cout << dp[i] << ' ';
    //}
    //cout << endl;
    //FOR(i, 0, n + 1) {
    //    cout << dp_log[i] << ' ';
    //}
    //cout << endl;

    ll ans = INF * INF;
    int idx = -1;
    FOR(i, 0, n + 1) {
        if (distance[n + 1] - distance[i] > k) continue;
        if (ans > dp[i]) {
            ans = dp[i];
            idx = i;
        }
    }
    cout << ans << endl;
    vector<int> ans_index_list;
    while (idx > 0) {
        ans_index_list.push_back(idx);
        idx = dp_log[idx];
    }
    reverse(all(ans_index_list));
    cout << ans_index_list.size() << endl;
    FOR(i, 0, ans_index_list.size()) {
        cout << ans_index_list[i] << ' ';
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}