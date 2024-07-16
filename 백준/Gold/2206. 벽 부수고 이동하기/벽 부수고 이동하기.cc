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
int dy[4] = { 0,0,1,-1};
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    FOR(i, 0, n) {
        cin >> v[i];
    }

    vector<matrix> distance(n, matrix(m, vector<ll>(2, INF)));

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    // cost, 깨기권, x,y좌표
    pq.push({ 0,0,0,0 });
    distance[0][0][0] = 0;

    while (!pq.empty()) {
        int now_cost = pq.top()[0];
        int is_break = pq.top()[1];
        int now_x = pq.top()[2];
        int now_y = pq.top()[3];
        pq.pop();

        FOR(idx, 0, 4) {
            int next_x = now_x + dx[idx];
            int next_y = now_y + dy[idx];
            int next_cost = now_cost + 1;
            if (0 <= next_x && next_x < n && 0 <= next_y && next_y < m) {
                if (v[next_x][next_y] == '1' && is_break == 0) {
                    if (distance[next_x][next_y][0] > next_cost) {
                        distance[next_x][next_y][1] = next_cost;
                        pq.push({ next_cost, 1, next_x, next_y });
                    }
                }
                if (v[next_x][next_y] == '0' && is_break == 0) {
                    if (distance[next_x][next_y][0] > next_cost) {
                        distance[next_x][next_y][0] = next_cost;
                        pq.push({ next_cost, is_break, next_x, next_y });
                    }
                }
                if (v[next_x][next_y] == '0' && is_break == 1) {
                    if (distance[next_x][next_y][1] > next_cost) {
                        distance[next_x][next_y][1] = next_cost;
                        pq.push({ next_cost, is_break, next_x, next_y });
                    }
                }
            }
        }
    }
    //FOR(i, 0, n) {
    //    FOR(j, 0, m) {
    //        cout << distance[i][j][0] << ' ';
    //    }
    //    cout << endl;
    //}
    //FOR(i, 0, n) {
    //    FOR(j, 0, m) {
    //        cout << distance[i][j][1] << ' ';
    //    }
    //    cout << endl;
    //}
    if (distance[n - 1][m - 1][0] == INF && distance[n - 1][m - 1][1] == INF) {
        cout << -1 << endl;
    }
    else {
        cout << min(distance[n - 1][m - 1][0], distance[n - 1][m - 1][1]) + 1 << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}