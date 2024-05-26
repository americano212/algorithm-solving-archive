#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2147483647
#define ll long long
#define pll pair<ll, ll>
#define matrix vector<vector<ll>>
#define lcm(a, b) a *b / gcd(a, b)
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1000000007LL;

using namespace std;

void solve() {
    ll n;
    cin >> n;
    ll k = 0;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    while (1) {
        ll lower = 3 * k * (k - 1) + 2;
        ll upper = 3 * k * (k + 1) + 1;
        if (lower <= n && n <= upper) {
            cout << k + 1 << endl;
            break;
        }
        k++;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}