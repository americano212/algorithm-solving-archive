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
int max_idx = 0;
int max_cost = -1;

void dfs(int now, int now_cost, vector<vector<pll>>& v, vector<bool>& visit) {
    FOR(idx, 0, v[now].size()) {
        int next = v[now][idx].first;
        int next_cost = now_cost + v[now][idx].second;
        if (!visit[next]) {
            visit[next] = true;
            dfs(next, next_cost, v, visit);
        }
    }
    if (now_cost > max_cost) {
        max_cost = now_cost;
        max_idx = now;
    }
}

void solve() {
    cin >> n;
    vector<vector<pll>> v(n+1);
    int a, b, c;
    FOR(i, 1, n + 1) {
        cin >> a;
        while (1) {
            cin >> b;
            if (b == -1) break;
            cin >> c;
            v[a].push_back(make_pair(b, c));
        }
    }
    vector<bool> visit(n + 1, false);
    visit[1] = true;
    dfs(1, 0, v, visit);
    // cout << max_idx << ' ' << max_cost << endl;
    visit.assign(n + 1, false);
    visit[max_idx] = true;
    dfs(max_idx, 0, v, visit);
    cout << max_cost << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();

    return 0;
}