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
    int n;
    cin >> n;
    string command;
    int input;
    FOR(i, 0, n) {
        cin >> command;
        if (command == "push") {
            cin >> input;
            st.push(input);
        }
        if (command == "pop") {
            if (st.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << st.top() << endl;
                st.pop();
            }
        }
        if (command == "size") {
            cout << st.size() << endl;
        }
        if (command == "empty") {
            cout << st.empty() << endl;
        }
        if (command == "top") {
            if (st.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << st.top() << endl;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}