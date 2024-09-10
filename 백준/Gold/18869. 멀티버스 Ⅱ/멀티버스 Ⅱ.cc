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
    int n, m;
    cin >> m >> n;

    matrix mat(m, vector<ll>(n));

    vector<ll> v(n);
    vector<ll> temp(n);
    FOR(i, 0, m) {
        
        FOR(j, 0, n) cin >> v[j];
        temp = v;
        sort(all(temp));
        temp.erase(unique(all(temp)), temp.end());

        FOR(j, 0, n) {
            // cout << temp[j] << ' ' << v[j]
            ll idx = lower_bound(all(temp), v[j]) - temp.begin();
            mat[i][j] = idx;
        }
    }

    //FOR(i, 0, m) {
    //    FOR(j, 0, n) {
    //        cout << mat[i][j] << ' ';
    //    }
    //    cout << endl;
    //}
    ll ans = 0;
    FOR(i, 0, m) {
        FOR(j, i + 1, m) {
            bool flag = true;
            FOR(idx, 0, n) {
                if (mat[i][idx] != mat[j][idx]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans++;
        }
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