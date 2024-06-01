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

bool cmp(pair <int, int> a, pair <int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 2, 0);
    vector<int> h(n + 2, 0);

    v[1] = 1;
    v[2] = 1;
    h[2] = 1;

    if (n <= 2) {
        cout << v[n] + h[n] << endl;
        return;
    }

    FOR(i, 3, n + 1) {
        v[i] = (v[i - 1] + h[i - 1]) % 10007;
        h[i] = (v[i - 2] + h[i - 2]) % 10007;
    }

    cout << (v[n] + h[n]) % 10007 << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}