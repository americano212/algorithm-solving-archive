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
    int k, n;
    cin >> k >> n;

    vector<ll> v(k);
    ll max_length = 1;
    FOR(i, 0, k) {
        cin >> v[i];
        max_length = max(max_length, v[i]);
    }


    ll lt = 1;
    ll rt = max_length;
    ll mid;

    ll ans = 1;

    while (lt <= rt) {
        mid = (lt + rt) / 2;
        ll cnt = 0;

        
        FOR(i, 0, k) {
            cnt += v[i] / mid;
        }
        if (n > cnt) rt = mid - 1;
        else {
            lt = mid + 1;
            ans = max(ans, mid);
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}