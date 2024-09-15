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

const ll mod = 1'000'000'000LL;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
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
struct MOVE { int x; int y; int time; };

int n, m;

int calc_distance(vector<vector<pii>>& mat, int start, int end, int exclude) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0,start });
    vector<int> distance(n + 1, INF);
    distance[start] = 0;

    while (!pq.empty()) {
        int now_node = pq.top().second;
        int now_cost = pq.top().first;
        pq.pop();

        if (distance[now_node] < now_cost) continue;

        FOR(idx, 0, mat[now_node].size()) {
            int next_node = mat[now_node][idx].first;
            int next_cost = mat[now_node][idx].second + now_cost;
            if (next_node == exclude) continue;

            if (distance[next_node] > next_cost) {
                distance[next_node] = next_cost;
                pq.push({ next_cost, next_node });
            }
        }
    }
    return distance[end];
}

void solve() {
    cin >> n >> m;
    vector<vector<pii>> mat(n + 1);
    int u, v, w;
    FOR(_, 0, m) {
        cin >> u >> v >> w;
        mat[u].push_back({ v,w });
    }
    int x, y, z;
    cin >> x >> y >> z;

    int a = calc_distance(mat, x, y, -1);
    int b = calc_distance(mat, y, z, -1);
    int c = calc_distance(mat, x, z, y);
    if (a == INF || b == INF) {
        cout << -1 << ' ';
    }
    else {
        cout << a + b << ' ';
    }
    if (c == INF) {
        cout << -1 << endl;
    }
    else {
        cout << calc_distance(mat, x, z, y) << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}