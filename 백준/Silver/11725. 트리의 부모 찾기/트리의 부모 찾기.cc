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
int n;

void bfs(queue<int> qu, vector<ll>& parent, matrix& mat) {
    while (1) {
        if (qu.empty()) break;
        int now = qu.front();
        qu.pop();
        FOR(i, 0, mat[now].size()) {
            int next = mat[now][i];
            if (parent[next] == -1) {
                parent[next] = now;
                qu.push(next);
            }
        }
    }
}

void solve() {

    cin >> n;

    matrix mat(n + 1);
    int a, b;
    FOR(i, 0, n - 1) {
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    vector<ll> parent(n + 1, -1);

    queue<int> qu;
    qu.push(1);
    parent[1] = 1;
    bfs(qu, parent, mat);

    FOR(i, 2, n + 1) {
        cout << parent[i] << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}