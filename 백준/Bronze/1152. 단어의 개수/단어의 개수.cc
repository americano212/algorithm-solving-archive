#include <bits/stdc++.h>
#define endl '\n';
#define INF 2147483647
#define ll long long
#define FOR(x,y,n)  for(ll x=y;x<(n);x++) 
#define pll pair<ll, ll>
#define matrix vector<vector<ll>>
#define lcm(a, b) a *b / gcd(a, b)
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1000000007LL;

using namespace std;

void solve() {
    string s;
    getline(cin, s);
    int cnt = 0;
    if (s.length() == 1 && s[0] == ' ') {
        cout << 0;
        return;
    }
    FOR(i, 1, s.length()-1) {
        if (s[i] == ' ') cnt++;
    }
    cout << cnt + 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}