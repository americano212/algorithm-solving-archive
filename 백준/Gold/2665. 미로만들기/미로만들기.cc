#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define pll pair<ll, ll>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    FOR(i, 0, n) {
        cin >> v[i];
    }

    priority_queue<pair<int, pll>, vector< pair<int, pll>>, greater< pair<int, pll>>> pq;
    pq.push(make_pair(0, make_pair(0, 0)));
    matrix distance(n, vector<ll>(n, INF));
    distance[0][0] = 0;

    while (!pq.empty()) {
        int now_x = pq.top().second.first;
        int now_y = pq.top().second.second;
        int now_cost = pq.top().first;
        pq.pop();

        if (distance[now_x][now_y] < now_cost) continue;

        FOR(idx, 0, 4) {
            int next_x = now_x + dx[idx];
            int next_y = now_y + dy[idx];
            if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n) {
                int next_cost = now_cost;
                if (v[next_x][next_y] == '0') next_cost++;
                if (distance[next_x][next_y] > next_cost) {
                    distance[next_x][next_y] = next_cost;
                    pq.push(make_pair(next_cost, make_pair(next_x, next_y)));
                }
            }
        }
    }
    cout << distance[n - 1][n - 1] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}