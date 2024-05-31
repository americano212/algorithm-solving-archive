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

void recur(vector<vector<char>>& m, int start_x, int start_y, int size) {
    if (size == 1) return;
    int next_size = size / 3;

    FOR(i, start_x + next_size, start_x + 2 * next_size) {
        FOR(j, start_y + next_size, start_y + 2 * next_size) {
            m[i][j] = ' ';
        }
    }

    FOR(i, 0, 3) {
        FOR(j, 0, 3) {
            if (i == 1 && j == 1) continue;
            recur(m, start_x + i * next_size, start_y + j * next_size, next_size);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> m(n, vector<char>(n, '*'));

    recur(m, 0, 0, n);

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cout << m[i][j];
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}