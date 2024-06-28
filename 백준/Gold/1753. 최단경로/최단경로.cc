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

vector<pll> vec[20001];

void solve() {
    int v, e;
    int start;
    cin >> v >> e;
    cin >> start;
    

    int a, b, c;
    FOR(i, 0, e) {
        cin >> a >> b >> c;
        vec[a].push_back(make_pair(b, c));
    }
    vector<ll> distance(v + 1, INF);

    priority_queue< pll, vector<pll>, greater<pll>> pq;
    pq.push(make_pair(0, start));
    distance[start] = 0;

    while (!pq.empty()) {
        int now_node = pq.top().second;
        int now_cost = pq.top().first;
        pq.pop();

        if (distance[now_node] < now_cost) continue;

        FOR(i, 0, vec[now_node].size()) {
            int next_node = vec[now_node][i].first;
            int next_cost = vec[now_node][i].second + now_cost;

            if (distance[next_node] > next_cost) {
                distance[next_node] = next_cost;
                pq.push(make_pair(next_cost, next_node));
            }
        }
    }
    FOR(i, 1, v + 1) {
        if (distance[i] == INF) {
            cout << "INF" << endl;
            continue;
        }
        cout << distance[i] << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();

    return 0;
}