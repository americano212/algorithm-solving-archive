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
struct NODE { ll max_value; int max_index; ll now_value; int now_node; };
struct ITEM { bool isNum; int num = 0; char bracket = ' '; };
struct MOVE { int x; int y; int time; };

int b_search(vector<ll>& v, int start, int end, int target) {
    if (start == end) return start;

    int mid = (start + end) / 2;
    if (v[mid] >= target) {
        return b_search(v, start, mid, target);
    }
    else {
        return b_search(v, mid + 1, end, target);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    FOR(i, 0, n) cin >> v[i];

    sort(all(v));

    if (n <= 2) {
        cout << 0 << endl;
        return;
    }

    int ans = 0;

    FOR(target_idx, 0, n) {
        FOR(a, 0, n) {
            if (target_idx == a) continue;
            int target = v[target_idx];

            if (target_idx < a) {
                if (0 <= target_idx - 1) {
                    int b = b_search(v, 0, target_idx - 1, target - v[a]);
                    if (target == v[a] + v[b] && b != target_idx && a != target_idx) {
                        ans++;
                        break;
                    }
                }
                if (target_idx + 1 <= a - 1) {
                    int b = b_search(v, target_idx + 1, a - 1, target - v[a]);
                    if (target == v[a] + v[b] && b != target_idx && a != target_idx) {
                        ans++;
                        break;
                    }
                }
                if (a + 1 <= n - 1) {
                    int b = b_search(v, a + 1, n - 1, target - v[a]);
                    if (target == v[a] + v[b] && b != target_idx && a != target_idx) {
                        ans++;
                        break;
                    }
                }
            }
            else {
                if (0 <= a - 1) {
                    int b = b_search(v, 0, a - 1, target - v[a]);
                    if (target == v[a] + v[b] && b != target_idx && a != target_idx) {
                        ans++;
                        break;
                    }
                }
                if (a + 1 <= target_idx - 1) {
                    int b = b_search(v, a + 1, target_idx - 1, target - v[a]);
                    if (target == v[a] + v[b] && b != target_idx && a != target_idx) {
                        ans++;
                        break;
                    }
                }
                if (target_idx + 1 <= n - 1) {
                    int b = b_search(v, target_idx + 1, n - 1, target - v[a]);
                    if (target == v[a] + v[b] && b != target_idx ) {
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}