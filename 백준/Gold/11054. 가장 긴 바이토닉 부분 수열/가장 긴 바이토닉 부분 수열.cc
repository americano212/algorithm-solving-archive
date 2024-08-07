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
    int n;
    cin >> n;
    vector<int> v(n);
    FOR(i, 0, n) {
        cin >> v[i];
    }
    vector<int> dp1(n, 0);
    vector<int> dp2(n, 0);
    bool check = true;
    dp1[0] = 1;
    FOR(i, 0, n) {
        int max_idx = 0;
        check = true;
        FOR(j, 0, i) {
            if (v[i] > v[j]) {
                if (dp1[max_idx] < dp1[j]) {
                    max_idx = j;
                }
                else if (dp1[max_idx] == dp1[j] && v[max_idx] > v[j]) {
                    max_idx = j;
                }
                check = false;
            }
        }
        if (check) {
            dp1[i] = 1;
        }
        else {
            if (v[max_idx] == v[i]) {
                dp1[i] = dp1[max_idx];
            }
            else {
                dp1[i] = dp1[max_idx] + 1;
            }
        }
    }

    

    dp2[n - 1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        int max_idx = n - 1;
        check = true;
        for(int j = n - 1; j > i; j--) {
            if (v[i] > v[j]) {
                if (dp2[max_idx] < dp2[j]) {
                    max_idx = j;
                }
                else if (dp2[max_idx] == dp2[j] && v[max_idx] > v[j]) {
                    max_idx = j;
                }
                check = false;
            }
        }
        if (check) {
            dp2[i] = 1;
        }
        else {
            if (v[max_idx] == v[i]) {
                dp2[i] = dp2[max_idx];
            }
            else {
                dp2[i] = dp2[max_idx] + 1;
            }
        }
        
    }

    //FOR(i, 0, n) {
    //    cout << dp1[i] << ' ';
    //}
    //cout << endl;
    //FOR(i, 0, n) {
    //    cout << dp2[i] << ' ';
    //}
    //cout << endl;

    int ans = 0;
    FOR(i, 0, n) {
        ans = max(ans, dp1[i] + dp2[i] - 1);
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