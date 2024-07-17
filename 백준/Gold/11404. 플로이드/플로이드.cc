#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define pll pair<ll, ll>
#define pllp pair<ll, pll>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
#define all(v) v.begin(), v.end()
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1};
using namespace std;

void solve() {
    int n, m;
    cin >> n;
    cin >> m;
    ll a, b, c;

    matrix graph(n + 1, vector<ll>(n + 1, INF));

    FOR(i, 0, m) {
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }
    FOR(k, 1, n + 1) {
        graph[k][k] = 0;
        FOR(src, 1, n + 1) {
            FOR(dst, 1, n + 1) {
                graph[src][dst] = min(graph[src][dst], graph[src][k] + graph[k][dst]);
            }
        }
    }

    FOR(i, 1, n + 1) {
        FOR(j, 1, n + 1) {
            if (graph[i][j] == INF) {
                cout << 0 << ' ';
            }
            else {
                cout << graph[i][j] << ' ';
            }
            
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}