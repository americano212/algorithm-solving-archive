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
int n, m;
ll answer = INF;

void dfs(int now, vector<pll>& house, vector<pll>& chicken, vector<bool>& visit, int cnt) {
    if (cnt == m) {
        ll city_chicken_distance = 0;
        FOR(i, 0, house.size()) {
            ll chicken_distance = INF;
            FOR(j, 0, chicken.size()) {
                if(visit[j]) chicken_distance = min(chicken_distance, abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
            }
            city_chicken_distance += chicken_distance;
        }
        answer = min(answer, city_chicken_distance);
        return;
    }

    
    FOR(next, now + 1, chicken.size()) {
        visit[next] = true;
        dfs(next, house, chicken, visit, cnt + 1);
        visit[next] = false;
    }
}

void solve() {
    
    cin >> n >> m;
    vector<pll> house;
    vector<pll> chicken;
    int tmp;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cin >> tmp;
            if (tmp == 1) house.push_back(make_pair(i, j));
            if (tmp == 2) chicken.push_back(make_pair(i, j));
        }
    }
    vector<bool> visit(chicken.size(), false);

    FOR(i, 0, chicken.size()) {
        visit[i] = true;
        dfs(i, house, chicken, visit, 1);
        visit[i] = false;
    }
    cout << answer << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}