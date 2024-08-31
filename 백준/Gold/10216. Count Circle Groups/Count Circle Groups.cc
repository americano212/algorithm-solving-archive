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

vector<int> parent(3001);

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    int a = Find(x);
    int b = Find(y);
    if (a < b) parent[a] = b;
    else parent[b] = a;
}

bool Same(int x, int y) {
    int a = Find(x);
    int b = Find(y);
    return a == b;
}

bool isGroup(pllp a, pllp b) {
    ll x1, x2, y1, y2, r1, r2;
    x1 = a.second.first;
    y1 = a.second.second;
    r1 = a.first;

    x2 = b.second.first;
    y2 = b.second.second;
    r2 = b.first;
    if (pow(x2 - x1, 2) + pow(y2 - y1, 2) <= pow(r1 + r2, 2)) return true;
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<pllp> v(n);
    int x, y, r;
    FOR(i, 0, n) {
        cin >> x >> y >> r;
        v[i] = { r,{x,y} };
    }

    FOR(i, 0, 3001) parent[i] = i;


    FOR(i, 0, n) {
        FOR(j, i + 1, n) {
            if (isGroup(v[i], v[j])) {
                Union(i, j);
            }
        }
    }

    //FOR(i, 0, n) {
    //    cout << parent[i] << ' ';
    //}
    //cout << endl;

    ll ans = 0;
    vector<bool> visited(3001, false);
    FOR(i, 0, n) {
        if (visited[Find(i)] == true) continue;
        
        visited[Find(i)] = true;
        ans += 1;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    cin >> tc;
    while (tc--)solve();

    return 0;
}