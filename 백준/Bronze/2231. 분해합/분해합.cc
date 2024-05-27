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
    int n;
    cin >> n;
    vector<int> v(1000001, 0);
    FOR(i, 0, 1000001) {
        int sum = i;
        int tmp = i;
        while (tmp >= 10) {
            sum += tmp % 10;
            tmp = tmp / 10;
        }
        sum += tmp;
        if (1000001 > sum) {
            if (v[sum] == 0) v[sum] = i;
        }
        
    }
    cout << v[n] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}