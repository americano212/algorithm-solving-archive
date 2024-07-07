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


void solve() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<pll>> graph(n + 1);
    int a, b, cost;
    FOR(_, 0, m) {
        cin >> a >> b >> cost;
        graph[a].push_back(make_pair(b, cost));
    }
    int start, end;
    cin >> start >> end;
    vector<int> distance(n + 1, INF);
    vector<int> before_node(n + 1, -1);
    distance[start] = 0;
    before_node[start] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int now_node = pq.top().second;
        int now_cost = pq.top().first;
        pq.pop();

        if (distance[now_node] < now_cost) continue;

        FOR(idx, 0, graph[now_node].size()) {
            int next_node = graph[now_node][idx].first;
            int next_cost = graph[now_node][idx].second + now_cost;
            if (distance[next_node] > next_cost) {
                distance[next_node] = next_cost;
                before_node[next_node] = now_node;
                pq.push(make_pair(next_cost, next_node));

            }
        }
    }

    cout << distance[end] << endl;

    
    vector<int> tracking;
    tracking.push_back(end);

    int find_node = before_node[end];
    while (1) {
        if (find_node == 0) break;
        tracking.push_back(find_node);
        find_node = before_node[find_node];
    }

    cout << tracking.size() << endl;
    reverse(tracking.begin(), tracking.end());
    FOR(i, 0, tracking.size()) {
        cout << tracking[i] << ' ';
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