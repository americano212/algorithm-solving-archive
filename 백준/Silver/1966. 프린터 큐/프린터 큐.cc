#include <bits/stdc++.h>
#define endl '\n';
#define INF 2147483647
#define ll long long
#define FOR(x,y,n)  for(ll x=y;x<(n);x++) 
#define pll pair<ll, ll>
#define matrix vector<vector<ll>>
#define lcm(a, b) a *b / gcd(a, b)
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1000000007LL;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    deque<pair<int, int>> qu;
    int important;
    FOR(idx, 0, n) {
        cin >> important;
        qu.push_back(make_pair(important, idx));
    }

    int counter = 1;
    while (1) {
        int maximum = -1;
        FOR(i, 0, qu.size()) {
            maximum = max(maximum, qu[i].first);
        }
        
        if (qu[0].first < maximum) {
            qu.push_back(qu[0]);
            qu.pop_front();
        }
        else {
            if (qu[0].second == m) {
                cout << counter << endl;
                return;
            }
            else {
                qu.pop_front();
            }
            counter++;
        }
        
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    cin >> tc;
    while (tc--) solve();

    return 0;
}