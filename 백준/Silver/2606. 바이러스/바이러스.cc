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

void solve() {
    int n;
    int m;
    int a, b;
    cin >> n;
    cin >> m;

    matrix mat(n + 1, vector<ll>(n + 1, 0));

    FOR(i, 0, m) {
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }

    vector<bool> visit(n + 1, false);

    queue<int> qu;
    
    qu.push(1);
    visit[1] = true;

    while (!qu.empty()) {
        int node = qu.front();
        qu.pop();

        FOR(next, 1, n + 1) {
            if (!visit[next] && mat[node][next]) {
                qu.push(next);
                visit[next] = true;
            }
        }
    }
    int ans = -1;
    FOR(i, 0, n + 1) {
        if (visit[i]) ans++;
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