#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pllp pair<ll, pll>
#define pff pair<float, float>
#define pdd pair<double, double>
#define pldd pair<ld, ld>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
#define all(v) v.begin(), v.end()
#define btw(x,a,b) a<=x && x<b
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int dx6[6] = { 1,-1,0,0,0,0 };
int dy6[6] = { 0,0,1,-1,0,0 };
int dz6[6] = { 0,0,0,0,1,-1 };
int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

struct EDGE { ll start; ll end; ll cost; };
struct DOT3 { ll x; ll y; ll z; };
struct NODE { int x; int y; int dir; };
struct ITEM { bool isNum; int num = 0; char bracket = ' '; };


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> indegree(n + 1, 0);
    matrix graph(n + 1);
    int c;
    FOR(_, 0, m) {
        cin >> c;
        vector<int> singer(c);
        FOR(i, 0, c) {
            cin >> singer[i];
        }
        FOR(i, 1, c) {
            graph[singer[i - 1]].push_back(singer[i]);
            indegree[singer[i]]++;
        }
    }

    queue<int> qu;
    FOR(i, 1, n + 1) {
        if (indegree[i] == 0) qu.push(i);
    }
    if (qu.empty()) {
        cout << 0 << endl;
        return;
    }
    vector<int> ans;
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        ans.push_back(now);

        FOR(idx, 0, graph[now].size()) {
            int next = graph[now][idx];
            indegree[next]--;
            if (indegree[next] == 0) qu.push(next);
        }
    }

    if (ans.size() != n) {
        cout << 0 << endl;
    }
    else {
        FOR(i, 0, n) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}