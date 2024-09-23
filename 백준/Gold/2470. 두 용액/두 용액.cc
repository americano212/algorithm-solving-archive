#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647LL
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

const ll mod = 1'000'000'007LL;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int dx6[6] = { 1,-1,0,0,0,0 };
int dy6[6] = { 0,0,1,-1,0,0 };
int dz6[6] = { 0,0,0,0,1,-1 };
int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

struct EDGE { ll start; ll end; ll cost; };
struct DOT3 { ll x; ll y; ll z; };
struct NODE { int a; int b; int c; };
struct ITEM { bool isNum; int num = 0; char bracket = ' '; };
struct MOVE { int x; int y; int time; };

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    FOR(i, 0, n) cin >> v[i];
    sort(all(v));

    int max_a = 0, max_b = 0;
    int max_diff = INF;

    FOR(a, 0, n) {
        int target = -v[a];
        int b = upper_bound(all(v), target) - v.begin();
        //cout << a << ' ' << b << endl;
        if (b == n) b--;
        //cout << v[a] << ' ' << v[b] << endl;
        if (a == b) {
            if (btw(b + 1, 0, n)) {
                if (abs(v[a] + v[b + 1]) < max_diff) {
                    max_diff = abs(v[a] + v[b + 1]);
                    max_a = a; max_b = b + 1;
                }
            }
            if (btw(b - 1, 0, n)) {
                if (abs(v[a] + v[b - 1]) < max_diff) {
                    max_diff = abs(v[a] + v[b - 1]);
                    max_a = a; max_b = b - 1;
                }
            }
        }
        else {
            if (abs(v[a] + v[b]) < max_diff) {
                max_diff = abs(v[a] + v[b]);
                max_a = a; max_b = b;
            }
            if (a != b + 1) {
                if (btw(b + 1, 0, n)) {
                    if (abs(v[a] + v[b + 1]) < max_diff) {
                        max_diff = abs(v[a] + v[b + 1]);
                        max_a = a; max_b = b + 1;
                    }
                }
            }
            if (a != b - 1) {
                if (btw(b - 1, 0, n)) {
                    if (abs(v[a] + v[b - 1]) < max_diff) {
                        max_diff = abs(v[a] + v[b - 1]);
                        max_a = a; max_b = b - 1;
                    }
                }
            }
        }
        
    }
    cout << v[max_a] << ' ' << v[max_b] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}