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
    ll n, m, b;
    cin >> n >> m >> b;
    matrix mat(n,vector<ll>(m,0));

    ll sum = 0;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> mat[i][j];
            sum += mat[i][j];
        }
    }

    ll max_height = (b + sum) / (n * m);
    max_height = min(max_height, (ll)256);

    
    ll min_time = INF;
    ll ans_height = 0;

    FOR(height, 0, max_height+1) {
        ll time = 0;
        FOR(i, 0, n) {
            FOR(j, 0, m) {
                if (mat[i][j] > height) {
                    time += 2 * (mat[i][j] - height);
                } 
                if (mat[i][j] < height) {
                    time += height - mat[i][j];
                }
            }
        }
        if (min_time >= time) {
            min_time = time;
            ans_height = height;
        }
    }
    cout << min_time << ' ' << ans_height << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}