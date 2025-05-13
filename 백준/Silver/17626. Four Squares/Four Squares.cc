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
    vector<int> sqr;
    int cnt[50001] = {0};


    FOR(i, 1, (int) sqrt(50000) + 1) {
        if (i * i <= 50000) {
            sqr.push_back(i * i);
            cnt[i * i] = 1;
        }
    }

    FOR(_, 0, 3) {
        FOR(i, 0, sqr.size()) {
            FOR(j, 1, 50001) {
                int target_sqr = sqr[i];
                if (j + target_sqr <= 50000) {
                    if (cnt[j] != 0) {
                        if (cnt[j + target_sqr] == 0) {
                            cnt[j + target_sqr] = cnt[j] + 1;
                        } else {
                            cnt[j + target_sqr] = min(cnt[j + target_sqr], cnt[j] + 1);
                        }
                    }
                }
            }
        }
    }
    int n;
    cin >> n;
    cout << cnt[n] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)
        solve();

    return 0;
}
