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

int n, m;

void recur(vector<int>& v) {
    if (v.size() == m) {
        FOR(i, 0, m) {
            cout << v[i] << ' ';
        }
        cout << endl;
        return;
    }

    FOR(i, 1, n + 1) {
        if (!v.empty()) {
            if (v.back() <= i) {
                v.push_back(i);
                recur(v);
                v.pop_back();
            }
        }
        else {
            v.push_back(i);
            recur(v);
            v.pop_back();
        }
    }
}

void solve() {
    cin >> n >> m;

    vector<int> v;

    recur(v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}