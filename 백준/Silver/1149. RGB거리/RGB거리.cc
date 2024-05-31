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
    matrix m(3, vector<ll>(n + 1, 0));

    int a, b, c;
    FOR(i, 1, n + 1) {
        cin >> a >> b >> c;

        m[0][i] = min(m[1][i - 1], m[2][i - 1]) + a;
        m[1][i] = min(m[0][i - 1], m[2][i - 1]) + b;
        m[2][i] = min(m[1][i - 1], m[0][i - 1]) + c;
    }

    ll minimum = INF;
    FOR(i, 0, 3) {
        minimum = min(minimum, m[i][n]);
    }
    cout << minimum << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}