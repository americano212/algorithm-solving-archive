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

int n, m, v;

void dfs(int now, vector<bool>& visit, matrix& mat) {
    cout << now << " ";

    FOR(next, 1, n + 1) {
        if (mat[now][next] && visit[next] == false) {
            visit[next] = true;
            dfs(next, visit, mat);
        }
    }
}

void bfs(queue<int>& qu, vector<bool>& visit, matrix& mat) {
    while (1) {
        if (qu.empty()) break;
        int now = qu.front();
        qu.pop();
        cout << now << " ";

        FOR(next, 1, n + 1) {
            if (mat[now][next] && visit[next] == false) {
                visit[next] = true;
                qu.push(next);
            }
        }
    }
}

void solve() {
    
    cin >> n >> m >> v;
    matrix mat(n+1,vector<ll>(n+1, 0));


    int a, b;
    FOR(i, 0, m){
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    vector<bool> visit(n + 1, false);
    visit[v] = true;
    dfs(v, visit, mat);
    cout << endl;

    visit.assign(n + 1, false);
    visit[v] = true;
    queue<int> qu;
    qu.push(v);
    bfs(qu, visit, mat);
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}