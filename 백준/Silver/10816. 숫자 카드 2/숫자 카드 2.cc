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
    vector<ll> v(20000001, 0);
    int n, m;
    cin >> n;
    int tmp;
    FOR(i, 0, n) {
        cin >> tmp;
        v[tmp + 10000000] += 1;
    }
    cin >> m;
    FOR(i, 0, m) {
        cin >> tmp;
        cout << v[tmp + 10000000] << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}