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
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int n, e;

int dijkstra(int start, int end, vector<vector<pll>>& v) {
    vector<int> distance(n + 1, INF);

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(make_pair(0, start));
    distance[start] = 0;

    while (!pq.empty()) {
        int now_node = pq.top().second;
        int now_cost = pq.top().first;
        pq.pop();

        if (distance[now_node] < now_cost) continue;

        FOR(idx, 0, v[now_node].size()) {
            int next_node = v[now_node][idx].first;
            int next_cost = v[now_node][idx].second + now_cost;
            if (distance[next_node] > next_cost) {
                distance[next_node] = next_cost;
                pq.push(make_pair(next_cost, next_node));
            }
        }
    }

    return distance[end];
}

void solve() {
    
    cin >> n >> e;
    vector<vector<pll>> v(n + 1);
    int a, b, cost;
    FOR(i, 0, e) {
        cin >> a >> b >> cost;
        v[a].push_back(make_pair(b, cost));
        v[b].push_back(make_pair(a, cost));
    }

    int v1, v2;
    cin >> v1 >> v2;
    
    int case_a = dijkstra(1, v1, v);
    int case_b = dijkstra(1, v2, v);
    int case_c = dijkstra(1, n, v);
    // cout << case_a << ' ' << case_b << ' ' << case_c << ' ' << endl;

    if (case_a == INF || case_b == INF || case_c == INF) {
        cout << -1 << endl;
        return;
    }

    cout << dijkstra(v1, v2, v) + min(dijkstra(1, v1, v) + dijkstra(v2, n, v), dijkstra(1, v2, v) + dijkstra(v1, n, v));

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();

    return 0;
}