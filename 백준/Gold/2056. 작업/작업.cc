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

const ll mod = 1'000'000'000LL;
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
    int n;
    cin >> n;
    vector<int> time(n + 1, 0);
    matrix mat(n + 1);
    vector<int> indegree(n + 1, 0);

    int cnt, work;
   
    FOR(i, 1, n + 1) {
        cin >> time[i];
        cin >> cnt;
        FOR(_, 0, cnt) {
            cin >> work;
            mat[work].push_back(i);
            indegree[i] += 1;
        }
    }

    queue<int> qu;
    FOR(i, 1, n + 1) {
        if (indegree[i] == 0) qu.push(i);
    }

    vector<int> wait_time(n + 1, 0);
    int end_node = 0;
    while (!qu.empty()) {
        int node = qu.front();
        qu.pop();

        end_node = node;

        FOR(idx, 0, mat[node].size()) {
            int next = mat[node][idx];
            wait_time[next] = max(wait_time[next], time[node]);
            indegree[next] -= 1;
            if (indegree[next] == 0) {
                qu.push(next);
                // cout << "?? " << next <<' ' << wait_time[next] << endl;
                time[next] += wait_time[next];
            }
        }
    }
    int ans = 0;
    FOR(i, 1, n + 1) {
        //cout << time[i] << ' ' ;
        ans = max(ans, time[i]);
    }
    //cout << endl;
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}