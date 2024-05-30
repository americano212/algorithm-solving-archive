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

void recur(string& s, int start, int end) {
    if (start == end) return;
    int size = (end - start + 1) / 3;
    FOR(i, start + size, start + 2 * size) {
        s[i] = ' ';
    }
    recur(s, start, start + size - 1);
    recur(s, end - size + 1, end);
}

void solve() {
    int n;
    while (cin >> n) {
        string s;
        FOR(i, 0, pow(3, n)) {
            s.push_back('-');
        }
        // cout << s.size() << endl;
        recur(s, 0, s.size() - 1);
        cout << s << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}