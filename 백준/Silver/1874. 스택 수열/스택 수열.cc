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
    stack<ll> st;
    st.push(0);
    int n;
    cin >> n;

    vector<ll> L(n+1,0);

    FOR(i, 0, n) {
        cin >> L[i];
    }
    vector<char> res;

    int target;
    int pivot = 1;
    FOR(i, 0, n) {
        target = L[i];
        while (!st.empty()) {
            if (target > st.top()) {
                res.push_back('+');
                st.push(pivot);
                pivot++;
            }
            else if (target == st.top()) {
                res.push_back('-');
                st.pop();
                break;
            }
            else {
                cout << "NO" << endl;
                return;
            }

            if (st.top() == 0) break;
        }
    }
    FOR(i, 0, res.size()) {
        cout << res[i] << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}