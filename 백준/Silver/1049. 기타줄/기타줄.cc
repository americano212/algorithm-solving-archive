#include <bits/stdc++.h>
#define endl '\n';
#define INF 2147483647
#define ll long long
#define pll pair<ll, ll>
#define matrix vector<vector<ll>>
#define lcm(a, b) a *b / gcd(a, b)
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1000000007LL;

ll a, b, c, i, j, k, n, m, t, x, y, z;
ll test;
ll ans = 0;
ll result = 0;

bool flag;

using namespace std;

void solve() {
    cin >> n >> m;
    ll min_a = 1000;
    ll min_b = 1000;
    for (i = 0; i < m; i++) {
        cin >> a >> b;
        min_a = min(min_a, a);
        min_b = min(min_b, b);
    }
    result = 100000;
    if (n % 6) {
        x = n / 6 + 1;
    }
    else {
        x = n / 6;
    }

    for (i = x; i >= 0; i--) {
        if (6 * i - n >= 0) {
            result = min(result, min_a * i);
        }
        else {
            result = min(result, min_a * i + min_b * (n - 6 * i));
        }
    }
    cout << result;
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}