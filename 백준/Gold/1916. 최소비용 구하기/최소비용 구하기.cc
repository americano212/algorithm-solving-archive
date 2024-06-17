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

using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}


void solve() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<pll> v[1001];

    int a, b, cost;
    FOR(i, 0, m) {
        cin >> a >> b >> cost;
        v[a].push_back(make_pair(b, cost));
    }
    vector<ll> distance(n + 1, INF);
    int start, end;
    cin >> start >> end;
    distance[start] = 0;

    priority_queue< pll, vector<pll>, greater<pll> > pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        ll now_node = pq.top().second, now_cost = pq.top().first;
        pq.pop();

        if (distance[now_node] < now_cost) continue;

        FOR(i, 0, v[now_node].size()) {
            ll next_node = v[now_node][i].first;
            ll next_cost = v[now_node][i].second + now_cost;
            if (distance[next_node] > next_cost) {
                distance[next_node] = next_cost;
                pq.push(make_pair(next_cost, next_node));
            }
        }
    }

    cout << distance[end] << endl;
    //FOR(i, 1, n + 1) {
    //    cout << distance[i] << ' ';
    //}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}