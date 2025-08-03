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
    int n, t;
    cin >> n >> t;
    int now_x = 0, now_y = 0;
    int now_t = 0;
    int now_dir = 0;
    int time;
    string dir;
    FOR(i, 0, n) {
        cin >> time >> dir;
        now_x += dx[now_dir] * (time - now_t);
        now_y += dy[now_dir] * (time - now_t);
        now_t = time;
        if (dir[0] == 'r')
            now_dir = (now_dir + 4 + 1) % 4;
        if (dir[0] == 'l')
            now_dir = (now_dir + 4 - 1) % 4;
    }
    now_x += dx[now_dir] * (t - now_t);
    now_y += dy[now_dir] * (t - now_t);
    cout << now_x << ' ' << now_y << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)
        solve();

    return 0;
}
