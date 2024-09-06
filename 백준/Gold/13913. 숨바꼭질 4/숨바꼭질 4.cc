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
    int n, k;
    cin >> n >> k;

    queue<pii> qu;
    qu.push({n, 0});

    vector<int> dp(100001, INF); // 여기까지 시간 최소
    dp[n] = 0;
    vector<int> before(100001, -1); // 직전 NODE
    before[n] = n;

    while (!qu.empty()) {
        int now_node = qu.front().first;
        int now_time = qu.front().second;
        qu.pop();

        if (btw(now_node - 1, 0, 100001)) {
            if (dp[now_node - 1] > now_time + 1) {
                dp[now_node - 1] = now_time + 1;
                before[now_node - 1] = now_node;
                qu.push({ now_node - 1, now_time + 1 });
            }
        }
        if (btw(now_node + 1, 0, 100001)) {
            if (dp[now_node + 1] > now_time + 1) {
                dp[now_node + 1] = now_time + 1;
                before[now_node + 1] = now_node;
                qu.push({ now_node + 1, now_time + 1 });
            }
        }
        if (btw(now_node * 2, 0, 100001)) {
            if (dp[now_node * 2] > now_time + 1) {
                dp[now_node * 2] = now_time + 1;
                before[now_node * 2] = now_node;
                qu.push({ now_node * 2, now_time + 1 });
            }
        }
    }
    cout << dp[k] << endl;
    vector<int> ans;
    int pivot = k;
    while (true) {
        ans.push_back(pivot);
        if (pivot == n) break;
        pivot = before[pivot];
    }
    reverse(all(ans));

    FOR(i, 0, ans.size()) {
        cout << ans[i] << ' ';
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