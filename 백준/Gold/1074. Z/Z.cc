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

int r, c;

void recur(int size, int start_x, int start_y, int start_num) {
    if (start_x == c && start_y == r) {
        cout << start_num << endl;
        return;
    }

    int half = size / 2;

    FOR(i, 0, 2) {
        FOR(j, 0, 2) {
            if (start_x + half * i <= c && c < start_x + half * (i + 1) &&
                start_y + half * j <= r && r < start_y + half * (j + 1)) {
                int new_start_num = start_num;
                if (i == 1 && j == 0) new_start_num = start_num + half * half;
                if (i == 0 && j == 1) new_start_num = start_num + half * half * 2;
                if (i == 1 && j == 1) new_start_num = start_num + half * half * 3;
                recur(half, start_x + half * i, start_y + half * j, new_start_num);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n >> r >> c;
    recur(pow(2, n), 0, 0, 0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}