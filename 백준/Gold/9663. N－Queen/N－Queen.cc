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
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

ll n;
ll ans = 0;
int position[15] = { 0, }; 

bool check(int depth) {
    FOR(idx, 0, depth) {
        if (position[idx] == position[depth]) return false;
        if (abs(position[depth] - position[idx]) == depth - idx) return false;
    }
    return true;
}

void queen(int depth) {
    if (depth == n) {
        ans += 1;
        return;
    }

    FOR(i, 0, n) {
        position[depth] = i;
        if (check(depth)) {
            queen(depth + 1);
        }
    }
}

void solve() {
    cin >> n;
    queen(0);
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();

    return 0;
}