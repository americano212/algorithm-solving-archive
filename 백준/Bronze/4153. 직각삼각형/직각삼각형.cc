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

void solve() {
    vector<int> v(3);
    while (1) {
        cin >> v[0] >> v[1] >> v[2];
        if (!v[0] && !v[1] && !v[2]) break;
        sort(v.begin(), v.end());
        if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2]) {
            cout << "right" << endl;
        }
        else {
            cout << "wrong" << endl;
        }

        
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();

    return 0;
}