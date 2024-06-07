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
    int n, m;
    cin >> n >> m;
    matrix mat(n + 1, vector<ll>(n + 1, 0));

    FOR(i, 1, n + 1) {
        FOR(j, 1, n + 1) {
            cin >> mat[i][j];
        }
    }
    FOR(i, 1, n + 1) {
        FOR(j, 1, n + 1) {
            mat[i][j] = mat[i][j] + mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
        }
    }

    /*FOR(i, 0, n + 1) {
        FOR(j, 0, n + 1) {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }*/


    int x1, y1, x2, y2;
    int ans = 0;
    FOR(t, 0, m) {
        cin >> x1 >> y1 >> x2 >> y2;

        ans = mat[x2][y2] - mat[x2][y1 - 1] - mat[x1 - 1][y2] + mat[x1 - 1][y1 - 1];
        cout << ans << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}