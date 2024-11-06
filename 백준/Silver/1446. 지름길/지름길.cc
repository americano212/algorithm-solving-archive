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

const ll mod = 9901LL;
int dx[4] = { 1,0,-1,0 };
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
    int n, d;
    cin >> n >> d;
    vector<vector<pii>> mat(d + 1);
    int s, e, dist;
    FOR(_, 0, n) {
        cin >> s >> e >> dist;
        if (s <= d && e <= d && e - s > dist) mat[s].push_back({ e,dist });
    }
    FOR(node, 0, d) {
        mat[node].push_back({ node + 1,1 });
    }
    vector<int> distance(d + 1, INF);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0,0 });
    distance[0] = 0;

    while (!pq.empty()) {
        int now_node = pq.top().second;
        int now_cost = pq.top().first;
        pq.pop();
        //cout << now_node << ' ' << now_cost << endl;
        if (distance[now_node] < now_cost) continue;

        FOR(idx, 0, mat[now_node].size()) {
            int next_node = mat[now_node][idx].first;
            int next_cost = mat[now_node][idx].second + now_cost;
            if (distance[next_node] > next_cost) {
                distance[next_node] = next_cost;
                pq.push({ next_cost,next_node });
            }
        }
    }
    //cout << "??" << endl;
    cout << distance[d] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}