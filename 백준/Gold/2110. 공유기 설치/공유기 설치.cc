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

ll n, m;

ll bsearch(vector<ll>& v, ll l, ll r) {
    int mid = (l + r + 1) / 2;
    if (l == r) return mid;

    ll cnt = 1;
    int last_index = v[0];
    FOR(i, 1, n) {
        if (v[i] - last_index >= mid) {
            cnt++;
            last_index = v[i];
        }
    }

    if (cnt < m) return bsearch(v, l, mid - 1);
    else return bsearch(v, mid, r);
}

void solve() {
    cin >> n >> m;
    vector<ll> v(n);

    FOR(i, 0, n) {
        cin >> v[i];
    }
    sort(all(v));

    cout << bsearch(v, 1, v[n - 1] - v[0]) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}