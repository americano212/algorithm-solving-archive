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

struct EDGE {
    ll start;
    ll end;
    ll cost;
};

//struct CMP {
//    bool operator() (INFO a, INFO b) {
//        return a.cost > b.cost;
//    }
//};


void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pll>> mat(101);
    FOR(i, 1, 101) {
        FOR(j, 1, 7) {
            if (i + j <= 100) {
                mat[i].push_back({ i + j, 1 });
            }
        }
    }
    int a, b;
    FOR(i, 0, n + m) {
        cin >> a >> b;
        mat[a].clear();
        mat[a].push_back({ b,0 });
    }

    vector<int> ans(101, INF);

    queue<pll> qu;
    qu.push({ 1,0 });
    ans[1] = 0;

    while (!qu.empty()) {
        int now = qu.front().first;
        int now_cost = qu.front().second;
        qu.pop();
        FOR(idx, 0, mat[now].size()) {
            int next = mat[now][idx].first;
            int next_cost = mat[now][idx].second + now_cost;
            if (ans[next] > next_cost) {
                ans[next] = next_cost;
                qu.push({ next, next_cost });
            }

        }
    }
    cout << ans[100] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}