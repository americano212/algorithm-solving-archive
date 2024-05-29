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
    int n, k;
    cin >> n >> k;

    matrix m(n + 1, vector<ll>(k + 1, 0));

    int w, v;
    
    FOR(i, 1, n + 1) {
        cin >> w >> v;
        FOR(j, 0, k + 1) {
            if (j - w >= 0) {
                m[i][j] = max(m[i - 1][j], m[i - 1][j - w] + v);
            }
            else {
                m[i][j] = m[i - 1][j];
            }
            
        }
    }

    //FOR(i, 0, n + 1) {
    //    FOR(j, 0, k + 1) {
    //        cout << m[i][j]<< ' ';
    //    }
    //    cout << endl;
    //}
    cout << m[n][k] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}