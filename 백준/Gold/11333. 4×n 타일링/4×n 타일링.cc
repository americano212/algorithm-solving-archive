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

vector<ll> v(3334, 0);

void dynamic(vector<ll>& v) {
    v[0] = 1;
    v[1] = 3;
    FOR(i, 2, 3334) {
        v[i] += v[i - 1] * 3 % 1000000007;
        FOR(j, 2, i + 1) {
            v[i] += v[i - j] * 2 * j % 1000000007;
            v[i] %= 1000000007;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    if (n % 3 != 0) {
        cout << 0 << endl;
        return;
    }
    cout << v[n / 3] % 1000000007 << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    cin >> tc;
    dynamic(v);
    while (tc--) solve();

    return 0;
}