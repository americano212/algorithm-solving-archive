#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define pll pair<ll, ll>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1};
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    vector<bool> use(n + 1, false);
    FOR(i, 0, m) {
        cin >> v[i];
        use[v[i]] = true;
    }
    int gnomes_pivot = 0;
    int use_pivot = 1;
    while (gnomes_pivot <= m && use_pivot <= n + 1) {
        if (gnomes_pivot == m && use_pivot == n + 1) break;

        if (gnomes_pivot == m) {
            cout << use_pivot << endl;
            use_pivot++;
            continue;
        }

        if (use_pivot == n + 1) {
            cout << v[gnomes_pivot] << endl;
            gnomes_pivot++;
            continue;
        }

        if (use[use_pivot]) {
            use_pivot++;
            continue;
        }

        if (use_pivot < v[gnomes_pivot]) {
            cout << use_pivot << endl;
            use_pivot++;
        }
        else {
            cout << v[gnomes_pivot] << endl;
            gnomes_pivot++;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}