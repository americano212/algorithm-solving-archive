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
    matrix mat(n + 1,vector<ll>(n+1));

    FOR(i, 0, n) {
        FOR(j, 0, i + 1) {
            cin >> mat[i][j];
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            mat[i - 1][j] += max(mat[i][j], mat[i][j + 1]);
        }
    }
    cout << mat[0][0] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}