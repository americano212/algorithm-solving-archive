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

void dijkstra(vector<vector<pll>>& v, matrix& distance, int start){
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(make_pair(0, start));
    distance[start][start] = 0;

    while (!pq.empty()) {
        int now_node = pq.top().second;
        int now_cost = pq.top().first;
        pq.pop();
        if (distance[start][now_node] < now_cost) continue;

        FOR(idx, 0, v[now_node].size()) {
            int next_node = v[now_node][idx].first;
            int next_cost = v[now_node][idx].second + now_cost;
            // cout << start << ' ' << now_node << ' ' << now_cost << ' ' << next_node << ' ' << next_cost << endl;
            if (distance[start][next_node] > next_cost) {
                distance[start][next_node] = next_cost;
                pq.push(make_pair(next_cost, next_node));
            }
        }
    }
}

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<pll>> v(n + 1);
    int a, b, cost;
    FOR(i, 0, m) {
        cin >> a >> b >> cost;
        v[a].push_back(make_pair(b, cost));
    }
    matrix distance(n + 1, vector<ll>(n + 1, INF));
    FOR(start, 1, n + 1) {
        dijkstra(v, distance, start);
    }

    //FOR(i, 0, n + 1) {
    //    cout << distance[2][i] << ' ';
    //}
    ll max_distance = -1;
    FOR(home, 1, n + 1) {
        max_distance = max(max_distance, distance[home][x] + distance[x][home]);
    }
    cout << max_distance << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();

    return 0;
}