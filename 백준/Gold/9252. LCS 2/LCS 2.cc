#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647ll
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

const ll mod = 1'000'000'000LL;
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

struct ITEM { int cnt; int rx; int ry; int bx; int by; };

void solve() {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    s1 = "0" + s1;
    s2 = "0" + s2;
    int len1 = s1.size();
    int len2 = s2.size();
    matrix dp(len2, vector<ll>(len1, 0));

    FOR(i, 1, len2) {
        FOR(j, 1, len1) {
            if (s1[j] == s2[i]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    //FOR(i, 1, len2) {
    //    FOR(j, 1, len1) {
    //        cout << dp[i][j] << ' ';
    //    }
    //    cout << endl;
    //}
    cout << dp[len2 - 1][len1 - 1] << endl;

    int now_x = len2 - 1;
    int now_y = len1 - 1;

    string ans = "";

    while (1) {
        if (now_x == 0 || now_y == 0) break;

        if (dp[now_x][now_y] == dp[now_x][now_y - 1]) {
            now_y -= 1;
            continue;
        }

        if (dp[now_x][now_y] == dp[now_x - 1][now_y]) {
            now_x -= 1;
            continue;
        }

        ans = s1[now_y] + ans;
        now_x -= 1;
        now_y -= 1;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}