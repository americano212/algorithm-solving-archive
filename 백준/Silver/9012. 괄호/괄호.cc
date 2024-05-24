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
    string s;
    cin >> s;

    stack<char> L;

    bool yesFlag = true;

    FOR(i, 0, s.length()) {
        if (s[i] == '(') {
            L.push(s[i]);
        }
        else {
            if (L.empty()) {
                yesFlag = false;
                break;
            }
            L.pop();
        }
    }
    if (yesFlag == false) {
        cout << "NO" << endl;
        return;
    }
    if (L.empty()) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    cin >> tc;
    while (tc--) solve();

    return 0;
}