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
    int n;
    cin >> n;
    vector<ll> maximum(3, 0);
    vector<ll> minimum(3, 0);
    FOR(i, 0, 3) {
        cin >> maximum[i];
    }
    minimum = maximum;

    int a, b, c;
    int max_a, max_b, max_c;
    int min_a, min_b, min_c;
    FOR(i, 1, n) {
        cin >> a >> b >> c;
        max_a = a + max(maximum[0], maximum[1]);
        max_b = b + max(max(maximum[0], maximum[1]), maximum[2]);
        max_c = c + max(maximum[1], maximum[2]);
        maximum = { max_a,max_b,max_c };
        
        min_a = a + min(minimum[0], minimum[1]);
        min_b = b + min(min(minimum[0], minimum[1]), minimum[2]);
        min_c = c + min(minimum[1], minimum[2]);
        minimum = { min_a,min_b,min_c };

    }

    ll min_ans = INF, max_ans = 0;

    FOR(i, 0, 3) {
        max_ans = max(max_ans, maximum[i]);
        min_ans = min(min_ans, minimum[i]);
    }
    cout << max_ans << ' ' << min_ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}