#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pllp pair<ll, pll>
#define pff pair<float, float>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
#define all(v) v.begin(), v.end()
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

struct INFO {
    ll cost;
    ll node;
};

struct CMP {
    bool operator() (INFO a, INFO b) {
        return a.cost > b.cost;
    }
};

void solve() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> item(n + 1, 0);

    FOR(i, 1, n + 1) {
        cin >> item[i];
    }

    matrix mat(n + 1, vector<ll>(n + 1, 0));
    int a, b, c;
    FOR(i, 0, r) {
        cin >> a >> b >> c;
        mat[a][b] = c;
        mat[b][a] = c;
    }

    ll ans = 0;

    FOR(start, 1, n + 1) {
        vector<ll> distance(n + 1, INF);
        priority_queue<INFO, vector<INFO>, CMP> pq;
        // 거리, 노드
        pq.push({ 0, start });
        distance[start] = 0;

        while(!pq.empty()){
            int now_cost = pq.top().cost;
            int now_node = pq.top().node;
            pq.pop();

            if (distance[now_node] < now_cost) continue;

            FOR(next_node, 1, n + 1) {
                if (mat[now_node][next_node]) {
                    ll next_cost = now_cost + mat[now_node][next_node];
                    if (distance[next_node] > next_cost) {
                        // cout << mat[now_node][next_node] << next_cost << endl;
                        distance[next_node] = next_cost;
                        pq.push({ next_cost, next_node });
                    }
                }
            }
        }

        ll sum_item = 0;
        FOR(i, 1, n + 1) {
            if (distance[i] <= m) {
                sum_item += item[i];
            }
        }
        ans = max(sum_item, ans);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}