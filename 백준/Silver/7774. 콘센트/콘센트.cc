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

matrix mat(31, vector<ll>(31, -1));

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, m) cin >> b[i];
    sort(all(a));
    reverse(all(a));
    sort(all(b));
    reverse(all(b));

    int cnt_a = 1, cnt_b = 0;
    int max_a = 1;
    int i = 0, j = 0;
    while (true) {
        if (i == n && j == m)
            break;


        if (j == m) {
            break;
        }

        if (i == n) {
            if (cnt_b != 0) {
                cnt_b--;
                cnt_a += b[j];
                j++;
                max_a = max(max_a, cnt_a);
                continue;
            } else {
                break;
            }
        }


        if (cnt_b != 0) {
            cnt_b--;
            cnt_a += b[j];
            j++;
        } else {
            cnt_a--;
            cnt_b += a[i];
            i++;
        }
        // cout << cnt_a << ' ' << cnt_b << endl;
        max_a = max(max_a, cnt_a);
    }
    cout << max_a << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)
        solve();

    return 0;
}
