#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define pll pair<ll, ll>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

using namespace std;



void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    FOR(i, 0, n) {
        cin >> v[i];
    }

    int diff = INF;
    int ans = 0;

    FOR(i, 0, n) {
        FOR(j, i + 1, n) {
            FOR(k, j + 1, n) {
                if (diff > m - (v[i] + v[j] + v[k]) && m >= (v[i] + v[j] + v[k])) {
                    diff = m - (v[i] + v[j] + v[k]);
                    ans = v[i] + v[j] + v[k];
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}