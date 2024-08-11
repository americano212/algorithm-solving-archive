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
    int n;
    cin >> n;

    int a, b;
    vector<pii> v(n);
    FOR(i, 0, n) {
        cin >> a >> b;
        v[i] = { a,b };
    }
    sort(all(v));
    //FOR(i, 0, n) {
    //    cout << v[i].second << ' ';
    //}
    //cout << endl;
    vector<int> dp(n, 0);
    dp[0] = 1;
    FOR(i, 1, n) {
        int maximum = 0;
        FOR(j, 0, i) {
            if (v[j].second < v[i].second) {
                maximum = max(maximum, dp[j]);
            }
        }
        dp[i] = maximum + 1;
    }

    int temp = 0;
    FOR(i, 0, n) {
        temp = max(temp, dp[i]);
    }
    cout << n - temp << endl;
}



int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}