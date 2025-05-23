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

struct ITEM { bool isNum; int num = 0; char bracket = ' '; };


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
   
    FOR(i, 0, n) {
        cin >> v[i];
    }
    sort(all(v));

    vector<int> dp(k + 1, 0);

    FOR(i, 0, n) {
        int coin = v[i];
        // cout << "?? " << coin << endl;
        FOR(j, 1, k + 1) {
            if (coin == j) dp[j] += 1;

            if (j - coin >= 0) {
                dp[j] = dp[j] + dp[j - coin];
            }
            
        }
    }

    /*FOR(i, 1, k + 1) {
        cout << dp[i] << ' ';
    }cout << endl;*/
    cout << dp[k] << endl;
}



int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}