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
    int n;
    cin >> n;
    string command;
    int input;

    deque<int> dq;
    FOR(i, 0, n) {
        cin >> command;
        if (command == "push_back") {
            cin >> input;
            dq.push_back(input);
        }
        if (command == "push_front") {
            cin >> input;
            dq.push_front(input);
        }
        if (command == "front") {
            if (!dq.size()) {
                cout << -1 << endl;
            }
            else {
                cout << dq[0] << endl;
            }
        }
        if (command == "back") {
            if (!dq.size()) {
                cout << -1 << endl;
            }
            else {
                cout << dq[dq.size()-1] << endl;
            }
        }
        if (command == "size") {
            cout << dq.size() << endl;
        }
        if (command == "empty") {
            cout << dq.empty() << endl;
        }
        if (command == "pop_front") {
            if (!dq.size()) {
                cout << -1 << endl;
            }
            else {
                cout << dq[0] << endl;
                dq.pop_front();
            }
        }
        if (command == "pop_back") {
            if (!dq.size()) {
                cout << -1 << endl;
            }
            else {
                cout << dq[dq.size() - 1] << endl;
                dq.pop_back();
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