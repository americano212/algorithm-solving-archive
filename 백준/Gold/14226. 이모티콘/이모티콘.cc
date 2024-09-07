#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
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
int dy[4] = { 0,1,0,-1 };
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


void solve() {
    int s;
    cin >> s;
    vector<ll> dp(1001, INF);

    queue<pll> qu;
    qu.push({ 1,0 });

    while (!qu.empty()) {
        int now_num = qu.front().first;
        int now_time = qu.front().second;
        qu.pop();

        for (int i = 2; now_num * i <= 1000; i++) {
            if (dp[now_num * i] > now_time + i) {
                dp[now_num * i] = now_time + i;
                qu.push({ now_num * i, now_time + i });
            }
        }
        if (btw(now_num - 1, 2, 1001)) {
            if (dp[now_num - 1] > now_time + 1) {
                dp[now_num - 1] = now_time + 1;
                qu.push({ now_num - 1, now_time + 1 });
            }
        }
    }
    cout << dp[s] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}