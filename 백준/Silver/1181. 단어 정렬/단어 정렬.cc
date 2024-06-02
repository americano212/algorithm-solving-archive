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

bool string_cmp(string a, string b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}


void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    FOR(i, 0, n) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), string_cmp);
    v.erase(unique(v.begin(), v.end()), v.end());

    FOR(i, 0, v.size()) {
        cout << v[i] << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}