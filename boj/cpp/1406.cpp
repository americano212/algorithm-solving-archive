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
    string strn;
    char s, command;
    stack<char> left;
    stack<char> right;
    vector<int> v;
    cin >> strn;
    for (i = 0; i < strn.length(); i++) {
        left.push(strn[i]);
    }

    cin >> n;

    char tmp;
    for (i = 0; i < n; i++) {
        cin >> command;
        if (command == 'P') {
            cin >> s;
            left.push(s);
        } else if (command == 'L') {
            if (!left.empty()) {
                tmp = left.top();
                left.pop();
                right.push(tmp);
            }
        } else if (command == 'D') {
            if (!right.empty()) {
                tmp = right.top();
                right.pop();
                left.push(tmp);
            }
        } else {
            if (!left.empty()) {
                tmp = left.top();
                left.pop();
            }
        }
    }
    int l_size, r_size;
    l_size = left.size();

    for (i = 0; i < l_size; i++) {
        tmp = left.top();
        left.pop();
        right.push(tmp);
    }
    r_size = right.size();
    for (i = 0; i < r_size; i++) {
        tmp = right.top();
        right.pop();
        cout << tmp;
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}