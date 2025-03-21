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
    int n, m;
    cin >> n >> m;

    vector<int> indegree(n + 1, 0);
    matrix mat(n + 1);

    int a, b;
    FOR(i, 0, m) {
        cin >> a >> b;
        mat[a].push_back(b);
        indegree[b] += 1;
    }

    queue<int> qu;
    FOR(i, 1, n + 1) {
        if (indegree[i] == 0) qu.push(i);
    }

    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        cout << now << ' ';
        
        FOR(idx, 0, mat[now].size()) {
            int next = mat[now][idx];
            indegree[next] -= 1;
            if (indegree[next] == 0) qu.push(next);
        }
    }
    cout << endl;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}