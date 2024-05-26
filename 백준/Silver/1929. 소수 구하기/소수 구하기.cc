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

    bool prime[1000001];

    FOR(i, 0, 1000001) {
        prime[i] = true;
    }
    prime[1] = false;
    FOR(i, 2, 1000001) {
        if (prime[i] == true) {
            int cnt = 2;
            while (1) {
                if (i * cnt > 1000000) break;
                prime[i * cnt] = false;
                cnt++;
            }
        }
    }
    int m, n;
    cin >> m >> n;
    FOR(i, m, n + 1) {
        if (prime[i]) {
            cout << i << endl;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}