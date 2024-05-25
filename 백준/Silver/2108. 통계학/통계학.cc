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
    int n;
    
    cin >> n;
    vector<int> v(n);
    double sum = 0;

    vector<int> cnt(8001, 0);

    FOR(i, 0, n) {
        cin >> v[i];
        sum += v[i];
        cnt[v[i] + 4000] += 1;
    }
    cout << round(sum / n) + 0.0 << endl;

    sort(v.begin(), v.end());
    cout << v[n / 2] << endl;

    int cnt_max = *max_element(cnt.begin(), cnt.end());

    vector<int> mode_list;
    FOR(i, 0, 8001) {
        if (cnt[i] == cnt_max) {
            mode_list.push_back(i - 4000);
        }
    }
    sort(mode_list.begin(), mode_list.end());
    if (mode_list.size() == 1) {
        cout << mode_list[0] << endl;
    }
    else {
        cout << mode_list[1] << endl;
    }

    cout << v[n - 1] - v[0] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}