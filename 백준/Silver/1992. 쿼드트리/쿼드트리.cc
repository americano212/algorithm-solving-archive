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

void quad_tree(vector<string> &split_m, int x1,int y1,int x2, int y2) {
    int sum = 0;
    int size = x2 - x1;
    FOR(i, x1, x2) {
        FOR(j, y1, y2) {
            if (split_m[i][j] == '1') sum++;
        }
    }
    if (sum == size * size) {
        cout << "1";
        return;
    }
    if (sum == 0) {
        cout << "0";
        return;
    }

    int mid = size / 2;
    cout << "(";
    quad_tree(split_m, x1, y1, x1 + mid, y1 + mid);
    quad_tree(split_m, x1 , y1 + mid, x1 + mid, y2);
    quad_tree(split_m, x1 + mid, y1, x2, y1 + mid);
    quad_tree(split_m, x1 + mid, y1 + mid, x2, y2);
    cout << ")";
}

void solve() {
    int n;
    cin >> n;
    vector<string> m;

    string s;

    FOR(i, 0, n) {
        cin >> s;
        m.push_back(s);
    }

    quad_tree(m, 0, 0, n, n);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}