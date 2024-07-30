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
    int n, k;
    cin >> n >> k;
    vector<int> time(n + 1);
    FOR(i, 1, n + 1) {
        cin >> time[i];
    }
    
    vector<vector<int>> mat(n + 1);
    vector<int> indegree(n + 1, 0);
    int a, b;
    FOR(i, 0, k) {
        cin >> a >> b;
        mat[a].push_back(b);
        indegree[b] += 1;
    }

    vector<int> ans(n + 1, 0);
    queue<int> qu;

    FOR(i, 1, n + 1) {
        if (indegree[i] == 0) {
            // cout << "?? " << i << endl;
            qu.push(i);
            ans[i] = max(ans[i], time[i]);
        }
    }

    
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();

        // if (time[now] > ans[now]) continue;

        FOR(i, 0, mat[now].size()) {
            int next = mat[now][i];
            if (ans[now] + time[next] > ans[next]) {
                ans[next] = ans[now] + time[next];
                qu.push(next);
            }
            
        }
    }
    //FOR(i, 1, n + 1) {
    //    cout << ans[i] << ' ';
    //}
    //cout << endl;

    int w;
    cin >> w;
    cout << ans[w] << endl;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    cin >> tc;
    while (tc--)solve();

    return 0;
}