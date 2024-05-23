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
    vector<ll> L(100001);

    
    L[1] = INF;
    L[2] = INF;
    L[3] = 1;
    L[4] = INF;
    L[5] = 1;
    FOR(i, 6, 5001) {
        ll result = INF;
        if (L[i - 3] != INF) {
            result = min(result, L[i - 3] + 1);
        }
        if (L[i - 5] != INF) {
            result = min(result, L[i - 5] + 1);
        }
        L[i] = result;
    }

    int N;
    cin >> N;
    if (L[N] == INF) {
        cout << "-1" << endl;
    }
    else {
        cout << L[N] << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}