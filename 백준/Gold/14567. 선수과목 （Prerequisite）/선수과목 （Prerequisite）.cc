#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647LL
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
int dy[4] = { 0,-1,0,1 };
int dx6[6] = { 1,-1,0,0,0,0 };
int dy6[6] = { 0,0,1,-1,0,0 };
int dz6[6] = { 0,0,0,0,1,-1 };
int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

struct EDGE { ll start; ll end; ll cost; };
struct DOT3 { ll x; ll y; ll z; };
struct NODE { ll max_value; int max_index; ll now_value; int now_node; };
struct ITEM { bool isNum; int num = 0; char bracket = ' '; };
struct MOVE { int x; int y; int time; };


void solve() {
    int n, m;
    cin >> n >> m;
    matrix graph(n + 1);
    vector<int> indegree(n + 1, 0);

    int a, b;
    FOR(_, 0, m) {
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b] += 1;
    }
    vector<int> ans(n + 1, 0);
    // {과목, 학기}
    queue<pii> qu;
    FOR(i, 1, n + 1) {
        if (indegree[i] == 0) {
            qu.push({ i,1 });
            ans[i] = 1;
        }
    }
    while (!qu.empty()) {
        pii now = qu.front();
        qu.pop();

        FOR(idx, 0, graph[now.first].size()) {
            int next_node = graph[now.first][idx];
            indegree[next_node] -= 1;
            if (indegree[next_node] == 0) {
                qu.push({ next_node,now.second + 1 });
                ans[next_node] = now.second + 1;
            }
        }
    }

    FOR(i, 1, n + 1) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}