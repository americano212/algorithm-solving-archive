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

int n;
int max_cost = -1;
int max_node = 0;

void dfs(int now, int cost, vector<vector<pll>>& mat, vector<bool>& visit) {
    bool check_next = false;
    FOR(idx, 0, mat[now].size()) {
        int next = mat[now][idx].first;
        int next_cost = mat[now][idx].second;
        if (!visit[next]) {
            check_next = true;
            visit[next] = true;
            dfs(next, cost + next_cost, mat, visit);
        }
    }
    if (!check_next && cost > max_cost) {
        max_cost = cost;
        max_node = now;
    }
}

void solve() {
    cin >> n;
    vector<vector<pll>> mat(n + 1);
    int a, b, c;
    FOR(i, 0, n - 1) {
        cin >> a >> b >> c;
        mat[a].push_back(make_pair(b, c));
        mat[b].push_back(make_pair(a, c));
    }
    vector<bool> visit(n + 1, false);
    visit[1] = true;
    dfs(1, 0, mat, visit);
    // cout << max_cost << ' ' << max_node << endl;
    visit.assign(n + 1, false);
    visit[max_node] = true;
    dfs(max_node, 0, mat, visit);
    cout << max_cost <<  endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();

    return 0;
}