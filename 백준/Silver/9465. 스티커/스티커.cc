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
    matrix board(3, vector<ll>(n + 1, 0));

    matrix mat(2, vector<ll>(n + 1, 0));

    FOR(i, 0, 2) {
        FOR(j, 0, n) {
            cin >> mat[i][j];
        }
    }

    board[0][0] = 0;            // 안붙, 안붙
    board[1][0] = mat[0][0];    // 붙, 안붙
    board[2][0] = mat[1][0];    // 안붙, 붙

    FOR(i, 1, n) {
        ll temp = 0;
        FOR(j, 0, 3) {
            temp = max(temp, board[j][i - 1]);
        }
        board[0][i] = temp;
        board[1][i] = max(board[0][i - 1], board[2][i - 1]) + mat[0][i];
        board[2][i] = max(board[0][i - 1], board[1][i - 1]) + mat[1][i];
    }
    ll ans = 0;
    FOR(i, 0, 3) {
        ans = max(ans, board[i][n - 1]);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    cin >> tc;
    while (tc--) solve();

    return 0;
}