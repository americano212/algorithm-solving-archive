#include <bits/stdc++.h>
#define FOR(x, y, n) for (int x = y; x < (n); x++)
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
#define lcm(a, b) a *b / gcd(a, b)
#define all(v) v.begin(), v.end()
#define btw(x, a, b) a <= x &&x < b
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 10007LL;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int dx6[6] = {1, -1, 0, 0, 0, 0};
int dy6[6] = {0, 0, 1, -1, 0, 0};
int dz6[6] = {0, 0, 0, 0, 1, -1};
int dx8[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy8[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;


void solve() {
    int t;
    cin >> t;
    FOR(c, 1, t + 1) {
        cout << "Case #" << c << ": ";
        int n;
        cin >> n;
        vector<pll> v(n * 2);
        ll tmp;
        FOR(i, 0, n * 2) {
            cin >> tmp;
            v[i] = {tmp, 0};
        };
        FOR(i, 0, n * 2) {
            if (v[i].second == 0) {
                v[i].second = 1;
                cout << v[i].first << ' ';
                FOR(j, i + 1, n * 2) {
                    if (v[j].second == 0 && v[j].first * 3 == v[i].first * 4) {
                        v[j].second = 1;
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)
        solve();

    return 0;
}
