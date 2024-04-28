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
    vector<ll> L(100001);

    for (i = 1; i < 100001; i++) {
        L[i] = i;
    }
    for (i = 1; i < 100001; i++) {
        int sqrt_i = (int)(sqrt(i));
        if (i - sqrt_i * sqrt_i == 0) {
            L[i] = 1;
        }
        else {
            for (j = 1; j < (int)(sqrt(i) + 1); j++) {
                L[i] = min(L[i], L[i - j * j] + 1);
            }
        }
    }

    cin >> n;
    cout << L[n] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}