#include <bits/stdc++.h>
#define FOR(x,n)  for(int x=0;x<(n);x++) 
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
    vector<ll> L(100001);

    int N;
    cin >> N;
    FOR(i, N) {
        cin >> L[i];
    }
    double max = *max_element(L.begin(), L.end());
    double sum = accumulate(L.begin(), L.end(),0);
    cout << 100 * sum / max / N;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}