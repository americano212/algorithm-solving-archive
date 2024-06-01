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
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    matrix m(s2.length() + 1, vector<ll>(s1.length() + 1, 0));

    FOR(i, 1, s2.length() + 1) {
        FOR(j, 1, s1.length() + 1) {
            ll maximum = max(m[i][j - 1], m[i - 1][j]);
            if (s1[j - 1] == s2[i - 1]) {
                maximum = m[i - 1][j - 1] + 1;
            }
            m[i][j] = maximum;
        }
    }

    //FOR(i, 1, s2.length() + 1) {
    //    FOR(j, 1, s1.length() + 1) {
    //        cout << m[i][j] << ' ';
    //    }
    //    cout << endl;
    //}

    cout << m[s2.length()][s1.length()] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}