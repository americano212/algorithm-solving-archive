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

void solve() {
    stack<int> st;
    int k;
    cin >> k;
    int tmp;
    FOR(i, 0, k) {
        cin >> tmp;
        if (tmp) st.push(tmp);
        else st.pop();
    }

    ll sum = 0;

    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }
    cout << sum << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}