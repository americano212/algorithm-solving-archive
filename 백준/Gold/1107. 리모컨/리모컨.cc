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
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int dx6[6] = { 1,-1,0,0,0,0 };
int dy6[6] = { 0,0,1,-1,0,0 };
int dz6[6] = { 0,0,0,0,1,-1 };
int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

struct EDGE { ll start; ll end; ll cost; };
struct COORDINATE { ll x; ll y; ll z; };

struct ITEM { bool isNum; int num = 0; char bracket = ' '; };

struct NODE { int x; int y; int dir; };




void dfs(int depth, int num, vector<int>& btn, priority_queue<pii, vector<pii>, greater<pii>>& qu) {
    qu.push({ depth, num });
    if (depth < 6) {
        FOR(i, 0, btn.size()) {
            dfs(depth + 1, num * 10 + btn[i], btn, qu);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<bool> visit(1'000'000, false);
    vector<bool> check(10, true);
    
    int cant_use;
    FOR(i, 0, m) {
        cin >> cant_use;
        check[cant_use] = false;
    }
    vector<int> btn;
    FOR(i, 0, 10) {
        if (check[i]) btn.push_back(i);
    }

    //FOR(i, 0, btn.size()) {
    //    cout << btn[i] << ' ';
    //}
    //cout << endl;

    priority_queue<pii, vector<pii>, greater<pii>> qu;
    qu.push({ 0,100 });
    visit[100] = true;

    FOR(i, 0, btn.size()) {
        dfs(1, btn[i], btn, qu);
    }

    while (!qu.empty()) {
        int now = qu.top().second;
        int ans = qu.top().first;
        qu.pop();
        if (now == n) {
            cout << ans << endl;
            return;
        }

        if (now + 1 < 1000000 && visit[now + 1] == false) {
            visit[now + 1] = true;
            qu.push({ ans + 1, now + 1 });
        }
        if (now - 1 >= 0 && visit[now - 1] == false) {
            visit[now - 1] = true;
            qu.push({ ans + 1,now - 1 });
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}