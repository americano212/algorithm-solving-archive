#include <bits/stdc++.h>
#define endl '\n';
#define INF 2147483647;
#define ll long long
#define pll pair<ll, ll>
#define matrix vector<vector<ll>>
#define lcm(a, b) a *b / gcd(a, b)
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1000000007LL;

ll a, b, c, i, j, k, n, m, t;
ll test;
ll ans = 0;
ll result = 0;

bool flag;

using namespace std;

void solve() {
    string s, strn;
    stack<string> stk;
    cin >> strn;
    flag = false;
    for (i = 0; i < strn.length(); i++) {
        s = strn[i];
        if (s == "(") {
            stk.push(s);
            flag = true;
        } else {
            if (flag) {
                stk.pop();
                ans += stk.size();
            } else {
                stk.pop();
                ans += 1;
            }
            flag = false;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}