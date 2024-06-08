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
    int m;
    cin >> m;

    string s;
    int tmp;

    vector<bool> v(21, 0);

    FOR(i, 0, m) {
        cin >> s;
        if (s == "add") {
            cin >> tmp;
            v[tmp] = true;
        }
        if (s == "check") {
            cin >> tmp;
            cout << v[tmp] << endl;
        }
        if (s == "remove") {
            cin >> tmp;
            v[tmp] = false;
        }
        if (s == "toggle") {
            cin >> tmp;
            v[tmp] = !v[tmp];
        }
        if (s == "all") {
            FOR(j, 1, 21) {
                v[j] = true;
            }
        }
        if (s == "empty") {
            FOR(j, 1, 21) {
                v[j] = false;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}