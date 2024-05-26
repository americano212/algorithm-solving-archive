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
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return;
    }
    vector<int> v(n,0);

    FOR(i, 0, n) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int cutting = round(n * 0.15);
    double sum = 0;
    FOR(i, cutting, n - cutting)
        sum += v[i];
    cout << round(sum / (n - 2 * cutting));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}