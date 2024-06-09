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
    vector<string> v(n + m);

    FOR(i, 0, n + m) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<string> ans;
    int cnt = 0;

    FOR(i, 1, n + m) {
        if (v[i] == v[i - 1]) {
            ans.push_back(v[i]);
            cnt++;
        }
    }
    cout << cnt << endl;
    FOR(i, 0, ans.size()) {
        cout << ans[i] << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}