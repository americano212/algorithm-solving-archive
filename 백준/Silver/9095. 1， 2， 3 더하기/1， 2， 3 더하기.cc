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

    matrix m(4, vector<ll>(n + 1, 0));
    m[1][0] = 1;
    m[1][1] = 1;
    m[1][2] = 1;
    m[2][2] = 1;
    if (n <= 2) {
        cout << n << endl;
        return;
    }
    FOR(i, 3, n + 1) {
        m[1][i] = m[1][i - 1] + m[2][i - 1] + m[3][i - 1];
        m[2][i] = m[1][i - 2] + m[2][i - 2] + m[3][i - 2];
        m[3][i] = m[1][i - 3] + m[2][i - 3] + m[3][i - 3];
    }

    cout << m[1][n] + m[2][n] + m[3][n] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    cin >> tc;
    while (tc--) solve();

    return 0;
}