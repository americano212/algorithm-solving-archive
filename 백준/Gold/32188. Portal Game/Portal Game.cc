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
    int n, c;
    cin >> n >> c;

    vector<int> blue(n, -1);
    vector<int> red(n, -1);

    int t, a, b;
    FOR(_, 0, c) {
        cin >> t >> a >> b;
        if (t == 0) red[a] = b;
        if (t == 1) blue[a] = b;
    }

    vector<ll> dp(n, INF);
    queue<int> qu;
    qu.push(0);
    dp[0] = 0;

    while (!qu.empty()) {
        int now_node = qu.front();
        qu.pop();

        bool flag_move = true;
        bool flag_portal = false;

        if (red[now_node] != -1) {
            flag_move = false;
            flag_portal = true;
        }
        if (blue[now_node] != -1) {
            flag_portal = true;
        }

        if (flag_portal) {
            int next_node;
            if (red[now_node] != -1) next_node = red[now_node];
            else next_node = blue[now_node];

            if (dp[now_node] < dp[next_node]) {
                dp[next_node] = dp[now_node];
                qu.push(next_node);
            }
        }
        if (flag_move) {
            int next_node = now_node + 1;
            if (next_node >= n) continue;
            if (dp[now_node] + 1 < dp[next_node]) {
                dp[next_node] = dp[now_node] + 1;
                qu.push(next_node);
            }
        }
    }
    if (dp[n - 1] == INF) {
        cout << -1 << endl;
    }
    else {
        cout << dp[n - 1] << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}