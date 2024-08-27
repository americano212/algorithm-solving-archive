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
#define pdd pair<double, double>
#define pldd pair<ld, ld>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
#define all(v) v.begin(), v.end()
#define btw(x,a,b) a<=x && x<b
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int dx6[6] = { 1,-1,0,0,0,0 };
int dy6[6] = { 0,0,1,-1,0,0 };
int dz6[6] = { 0,0,0,0,1,-1 };
int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

struct EDGE { ll start; ll end; ll cost; };
struct DOT3 { ll x; ll y; ll z; };
struct NODE { int x; int y; int dir; };
struct ITEM { bool isNum; int num = 0; char bracket = ' '; };

void solve() {
    int v, e;
    cin >> v >> e;
    matrix mat(v + 1);
    FOR(_, 0, e) {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    vector<int> visited(v + 1, 0);
    queue<pii> qu; // {node, type}
    FOR(start, 1, v + 1) {
        if (visited[start] == 0) qu.push({ start,1 });
        visited[start] = 1;

        while (!qu.empty()) {
            int now_node = qu.front().first;
            int now_type = qu.front().second;
            qu.pop();

            FOR(idx, 0, mat[now_node].size()) {
                int next_node = mat[now_node][idx];
                if (visited[next_node] == 0) {
                    visited[next_node] = -now_type;
                    qu.push({ next_node, -now_type });
                }
                else {
                    if (visited[next_node] == now_type) {
                        cout << "NO" << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "YES" << endl;
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    cin >> tc;
    while (tc--)solve();

    return 0;
}