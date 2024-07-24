#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define ld long double
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


void solve() {
    int n, s;
    cin >> n >> s;
    
    vector<int> v(n);
    FOR(i, 0, n) {
        cin >> v[i];
    }
    vector<ll> prefix_sum(n + 1, 0);
    FOR(i, 0, n) {
        prefix_sum[i + 1] = prefix_sum[i] + v[i];
    }
    //FOR(i, 0, n + 1) {
    //    cout << prefix_sum[i] << ' ';
    //}
    //cout << endl;
    int a = 0;
    int b = 0;
    int shortest = INF;

    while (1) {
        if (prefix_sum[b] - prefix_sum[a] >= s) {
            shortest = min(shortest, b - a);
            a++;
        }
        else {
            if (b == n) break;
            b++;
        }
    }
    if (shortest == INF) shortest = 0;
    
    cout << shortest << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}