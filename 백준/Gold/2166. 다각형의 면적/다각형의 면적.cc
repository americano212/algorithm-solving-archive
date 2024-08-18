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

ld tri_size(pll a, pll b, pll c) {
    pll vec1 = { b.first - a.first,b.second - a.second };
    pll vec2 = { c.first - b.first,c.second - b.second };
    ld result = vec1.first * vec2.second - vec2.first * vec1.second;
    return result / 2;
}

void solve() {
    int n;
    cin >> n;
    vector<pii> v(n);
    FOR(i, 0, n) {
        cin >> v[i].first >> v[i].second;
    }

    ld ans = 0;
    FOR(i, 1, n - 1) {
        ans += tri_size( v[0], v[i], v[i + 1] );
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(ans) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}