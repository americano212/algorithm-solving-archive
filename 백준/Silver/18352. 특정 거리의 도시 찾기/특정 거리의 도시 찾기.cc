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
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    vector<vector<int>> v(n + 1);
    int a, b;
    FOR(i, 0, m) {
        cin >> a >> b;
        v[a].push_back(b);
    }
    
    vector<int> distance(n + 1, INF);

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(make_pair(0, x));
    distance[x] = 0;

    while (!pq.empty()) {
        int now_node = pq.top().second;
        int now_cost = pq.top().first;
        pq.pop();

        if (distance[now_node] < now_cost) continue;

        FOR(idx, 0, v[now_node].size()) {
            int next_node = v[now_node][idx];
            int next_cost = now_cost + 1;
            if (distance[next_node] > next_cost) {
                distance[next_node] = next_cost;
                pq.push(make_pair(next_cost, next_node));
            }
        }
    }
    bool is_exist = false;
    FOR(i, 1, n + 1) {
        if (distance[i] == k) {
            cout << i << endl;
            is_exist = true;
        }
    }
    if (!is_exist) {
        cout << -1 << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}