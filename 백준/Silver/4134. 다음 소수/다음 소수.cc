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
    vector<ll> L(100001);
    ll N;
    cin >> N;
    if (N == 0 || N == 1 || N ==2) {
        cout << 2 << endl;
        return;
    }
    while (1) {
        bool isPrime = true;
        FOR(i, 2, sqrt(N)+1) {
            if (N % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) break;
        N++;
    }
    cout << N << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    cin >> tc;
    while (tc--) solve();

    return 0;
}