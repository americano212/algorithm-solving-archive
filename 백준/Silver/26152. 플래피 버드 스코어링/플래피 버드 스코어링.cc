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




int binary_search(int l, int r, ll target, vector<ll>& v) {
    if (l == r) return l;
    // 같거나 크면 왼쪽 선택
    int mid = (l + r) / 2;
    if (target > v[mid]) {
        return binary_search(l, mid, target, v);
    }
    else {
        return binary_search(mid + 1, r, target, v);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    FOR(i, 0, n) {
        cin >> a[i];
    }
    FOR(i, 0, n) {
        cin >> b[i];
    }
    

    vector<ll> v(n + 1, 0);
    v[0] = a[0] - b[0];
    FOR(i, 1, n) {
        v[i] = min(v[i - 1], a[i] - b[i]);
    }
    //FOR(i, 0, n + 1) {
    //    cout << v[i] << ' ';
    //}
    //cout << endl;

    int q;
    cin >> q;
    ll w;
    FOR(i, 0, q) {
        cin >> w;
        int ans = binary_search(0, n, w, v);
        cout << ans << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}