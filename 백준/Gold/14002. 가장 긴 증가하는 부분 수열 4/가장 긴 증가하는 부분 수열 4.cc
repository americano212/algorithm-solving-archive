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
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
#define all(v) v.begin(), v.end()
#define btw(x,a,b) a<=x && x<b
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
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
    int n;
    cin >> n;
    vector<int> v(n);
    FOR(i, 0, n) {
        cin >> v[i];
    }
    int cnt = 0;
    vector<int> dp(n, 1);
    FOR(i, 0, n) {
        int temp_dp = 0;
        FOR(j, 0, i) {
            if (v[i] > v[j]) {
                temp_dp = max(temp_dp, dp[j]);
            }
        }
        dp[i] = temp_dp + 1;
        cnt = max(cnt, dp[i]);
    }
    /*FOR(i, 0, n) {
        cout << dp[i] << ' ';
    }
    cout << endl;*/

    
    cout << cnt << endl;
    vector<int> ans;
    FOR(i, 0, n) {
        if (dp[n - i - 1] == cnt) {
            ans.push_back(v[n - i - 1]);
            cnt -= 1;
        }
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