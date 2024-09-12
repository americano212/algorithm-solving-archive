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
    int n;
    cin >> n;
    vector<pll> v(n);
    ll a, b;
    FOR(i, 0, n) {
        cin >> a >> b;
        if (a <= b) {
            v[i] = { a,b };
        }
        else {
            v[i] = { b,a };
        }
        
    }
    sort(all(v));

    ll ans = 0;

    pll now = v[0];
    FOR(i, 1, n) {
        /*cout << "? " << i << endl;
        cout << now.first << ' ' << now.second << endl;*/
        // 포함될 때 
        if (btw(v[i].first, now.first, now.second + 1) && btw(v[i].second, now.first, now.second + 1)) {
            //cout << "!" << endl;
            continue;
        } 
        // 겹칠 때 ~btw(v[i].second, now.first, now.second + 1)
        else if (btw(v[i].first, now.first, now.second + 1) && (now.second < v[i].second)) {
            //cout << "!!" << endl;
            now.second = v[i].second;
        }
        else {
            ans += now.second - now.first;
            now = v[i];
        }
        
    }
    ans += now.second - now.first;
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}