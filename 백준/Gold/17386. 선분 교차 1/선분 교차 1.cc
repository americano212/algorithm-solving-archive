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
struct COORDINATE { ll x; ll y; ll z; };
struct NODE { int x; int y; int dir; };

struct ITEM { bool isNum; int num = 0; char bracket = ' '; };

int ccw(pii p1, pii p2, pii p3) {
    pll vec1 = { p2.first - p1.first, p2.second - p1.second };
    pll vec2 = { p3.first - p2.first, p3.second - p2.second };
    
    ll z = vec1.first * vec2.second - vec1.second * vec2.first;
    if (z > 0) return 1;
    if (z < 0) return -1;
    return 0;
}

void solve() {
    pii a, b, c, d;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;
    cin >> d.first >> d.second;

    if (ccw(a, b, c) * ccw(a, b, d) == -1 && ccw(c, d, a) * ccw(c, d, b) == -1) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}