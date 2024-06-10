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

ll a, b, c;

ll recur(ll power) {
    if (power == 0) return 1;
    if (power == 1) return a % c;

    ll tmp = recur(power / 2) % c;
    if (power % 2 == 1) {
        return tmp * tmp % c * a % c;
    }
    else {
        return tmp * tmp % c;
    }
        
}

void solve() {
    
    cin >> a >> b >> c;

    ll ans = recur(b) % c;

    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}