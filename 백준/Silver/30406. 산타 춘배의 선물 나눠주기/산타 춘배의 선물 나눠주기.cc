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
    vector<int> v(4, 0);
    int temp;
    FOR(i, 0, n) {
        cin >> temp;
        v[temp]++;
    }
    //FOR(i, 0, 4) {
    //    cout << v[i] << ' ';
    //}
    //cout << endl;
    ll ans = 0;
    
    // 0,3 1,2 
    temp = min(v[0], v[3]);
    ans += temp * 3;
    v[0] -= temp;
    v[3] -= temp;
    temp = min(v[1], v[2]);
    ans += temp * 3;
    v[1] -= temp;
    v[2] -= temp;

    // 1,3 0,2
    temp = min(v[1], v[3]);
    ans += temp * 2;
    v[1] -= temp;
    v[3] -= temp;
    temp = min(v[0], v[2]);
    ans += temp * 2;
    v[0] -= temp;
    v[2] -= temp;

    // 0,1 2,3
    temp = min(v[0], v[1]);
    ans += temp * 1;
    v[0] -= temp;
    v[1] -= temp;
    temp = min(v[2], v[3]);
    ans += temp * 1;
    v[2] -= temp;
    v[3] -= temp;

    cout << ans << endl;
}



int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}