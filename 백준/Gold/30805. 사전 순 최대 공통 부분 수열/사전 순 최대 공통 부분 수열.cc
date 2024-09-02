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
    cin >> n;
    vector<int> v1(n);
    FOR(i, 0, n) cin >> v1[i];

    cin >> m;
    vector<int> v2(m);
    FOR(i, 0, m) cin >> v2[i];

    int v1_start = 0;
    int v2_start = 0;

    vector<int> cache;

    while (1) {
        if (v1_start == n || v2_start == m) break;
        int max_value = -1;
        int max_idx_v1 = 0;
        int max_idx_v2 = 0;

        FOR(i, v1_start, n) {
            FOR(j, v2_start, m) {
                if (v1[i] == v2[j]) {
                    if (max_value < v1[i]) {
                        max_value = v1[i];
                        max_idx_v1 = i;
                        max_idx_v2 = j;
                    }
                }
            }
        }
        if (max_value != -1) {
            cache.push_back(max_value);
            v1_start = max_idx_v1 + 1;
            v2_start = max_idx_v2 + 1;
        }
        else {
            break;
        }
    }
    cout << cache.size() << endl;
    FOR(i, 0, cache.size()) {
        cout << cache[i] << ' ';
    } 
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}