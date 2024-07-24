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
#define btw(x,a,b) a<=x && x<b
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dx6[6] = { 1,-1,0,0,0,0 };
int dy6[6] = { 0,0,1,-1,0,0 };
int dz6[6] = { 0,0,0,0,1,-1 };
int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

struct EDGE { ll start; ll end; ll cost; };
struct COORDINATE { ll x; ll y; ll z; };


void solve() {
    int n, d, c;
    cin >> n >> d >> c;

    priority_queue<pll, vector<pll>, greater<pll>> pq;

    vector<vector<pll>> mat(n + 1);

    int a, b, s;
    FOR(i, 0, d) {
        cin >> a >> b >> s;
        mat[b].push_back({ a,s });
    }

    vector<int> distance(n + 1, INF);
    distance[c] = 0;
    pq.push({ 0,c });

    while (!pq.empty()) {
        int now_cost = pq.top().first;
        int now_node = pq.top().second;
        pq.pop();
        
        if (distance[now_node] < now_cost) continue;

        FOR(idx, 0, mat[now_node].size()) {
            int next_node = mat[now_node][idx].first;
            int next_cost = now_cost + mat[now_node][idx].second;
            if (distance[next_node] > next_cost) {
                distance[next_node] = next_cost;
                pq.push({ next_cost, next_node });
            }
        }
    }

    int maximum = 0;
    int virus_cnt = 0;
    FOR(i, 1, n + 1) {
        // cout << distance[i] << ' ';
        if (distance[i] != INF) {
            virus_cnt++;
            maximum = max(maximum, distance[i]);
        }
        
    }
    cout << virus_cnt << ' ' << maximum << endl;

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    cin >> tc;
    while (tc--)solve();

    return 0;
}