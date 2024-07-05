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
    int m, n;
    cin >> m >> n;
    vector<string> v(n);
    FOR(i, 0, n) {
        cin >> v[i];
    }

    priority_queue<pair<int, pll>, vector<pair<int, pll>>, greater<pair<int, pll>>> pq;

    pq.push(make_pair(0, make_pair(0, 0)));
    matrix distance(n, vector<ll>(m, INF));
    distance[0][0] = 0;

    while (!pq.empty()) {
        int now_cost = pq.top().first;
        int now_x = pq.top().second.second;
        int now_y = pq.top().second.first;
        pq.pop();

        if (distance[now_y][now_x] < now_cost) continue;

        FOR(i, 0, 4) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];
            if (0 <= next_x && next_x < m && 0 <= next_y && next_y < n) {
                int next_cost = now_cost;
                if (v[next_y][next_x] == '1') next_cost ++;

                if (distance[next_y][next_x] > next_cost) {
                    distance[next_y][next_x] = next_cost;
                    pq.push(make_pair(next_cost, make_pair(next_y, next_x)));
                }
            }
        }
    }
    cout << distance[n - 1][m - 1] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}