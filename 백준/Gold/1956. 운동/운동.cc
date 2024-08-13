#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pllp pair<ll, pll>
#define pff pair<float, float>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
#define all(v) v.begin(), v.end()
#define btw(x,a,b) a<=x && x<b
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dx6[6] = { 1,-1,0,0,0,0 };
int dy6[6] = { 0,0,1,-1,0,0 };
int dz6[6] = { 0,0,0,0,1,-1 };
int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

struct EDGE { ll start; ll end; ll cost; };
struct COORDINATE { ll x; ll y; ll z; };

struct ITEM { bool isNum; int num = 0; char bracket = ' '; };

void solve() {
    int n, m;
    cin >> n >> m;

    matrix graph(n + 1, vector<ll>(n + 1, INF));

    int a, b, c;
    FOR(i, 0, m) {
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    FOR(k, 1, n + 1) {
        graph[k][k] = 0;
        FOR(s, 1, n + 1) {
            FOR(e, 1, n + 1) {
                if (graph[s][k] == INF || graph[k][e] == INF) continue;
                graph[s][e] = min(graph[s][e], graph[s][k] + graph[k][e]);
            }
        }
    }
    //FOR(s, 1, n + 1) {
    //    FOR(e, 1, n + 1) {
    //        cout << graph[s][e] << ' ';
    //    }
    //    cout << endl;
    //}
    
    ll ans = INF;
    FOR(s, 1, n + 1) {
        FOR(e, 1, n + 1) {
            if (s == e) continue;
            if (graph[s][e] == INF || graph[e][s] == INF) continue;

            ans = min(ans, graph[s][e] + graph[e][s]);
        }
    }
    if (ans == INF) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}