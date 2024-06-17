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

    vector<int> v(n + 1, 0);
    FOR(i, 1, n + 1) {
        cin >> v[i];
    }
    if (n == 1) {
        cout << v[1] << endl;
        return;
    }
    if (n == 2) {
        cout << v[1] + v[2] << endl;
        return;
    }
    
    vector<ll> dp(n + 1, 0);
    dp[1] = v[1];
    dp[2] = v[1] + v[2];
    FOR(i, 3, n + 1) {
        dp[i] = max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]);
    }
    //FOR(i, 0, n + 1) {
    //    cout << dp[i] << ' ';
    //}
    cout << dp[n] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}