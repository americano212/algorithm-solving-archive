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
int blue = 0;
int white = 0;

void paper(matrix &mat, int x1, int y1, int x2, int y2) {
    int size = x2 - x1;
    int sum = 0;
    FOR(i, x1, x2) {
        FOR(j, y1, y2) {
            sum += mat[i][j];
        }
    }
    if (sum == size * size) {
        blue++;
        return;
    }
    if (sum == 0) {
        white++;
        return;
    }

    int half = size / 2;

    paper(mat, x1, y1, x1 + half, y1 + half);
    paper(mat, x1 + half, y1, x2, y1 + half);
    paper(mat, x1 , y1 + half, x1 + half, y2);
    paper(mat, x1 + half, y1 + half, x2, y2);
}

void solve() {
    int n;
    cin >> n;
    matrix mat(n, vector<ll>(n, 0));

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cin >> mat[i][j];
        }
    }

    paper(mat, 0, 0, n, n);
    cout << white << endl;
    cout << blue << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}