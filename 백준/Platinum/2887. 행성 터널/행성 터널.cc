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

struct EDGE { ll start; ll end; ll cost; };
struct COORDINATE { ll x; ll y; ll z; };


bool CMP_X(const pair<int, COORDINATE>& a, const pair<int, COORDINATE>& b) {
    return a.second.x < b.second.x;
}

bool CMP_Y(const pair<int, COORDINATE>& a, const pair<int, COORDINATE>& b) {
    return a.second.y < b.second.y;
}

bool CMP_Z(const pair<int, COORDINATE>& a, const pair<int, COORDINATE>& b) {
    return a.second.z < b.second.z;
}

vector<int> parent(100001);

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    int a = Find(x);
    int b = Find(y);
    if (a < b) {
        parent[a] = b;
    }
    else {
        parent[b] = a;
    }
}

bool Same(int x, int y) {
    int a = Find(x);
    int b = Find(y);
    return a == b ? true: false;
}

void solve() {
    int n;
    cin >> n;

    // order, XYZ
    vector<pair<int, COORDINATE>> v(n);

    int x, y, z;
    FOR(i, 0, n) {
        cin >> x >> y >> z;
        v[i] = { i, {x,y,z} };
    }

    priority_queue<pllp, vector<pllp>, greater<pllp>> pq;

    // x 기준 정렬
    sort(all(v), CMP_X);
    FOR(i, 1, n) {
        pq.push({ v[i].second.x - v[i - 1].second.x, {v[i].first, v[i - 1].first} });
    }

    // y 기준 정렬
    sort(all(v), CMP_Y);
    FOR(i, 1, n) {
        pq.push({ v[i].second.y - v[i - 1].second.y, {v[i].first, v[i - 1].first} });
    }

    // z 기준 정렬
    sort(all(v), CMP_Z);
    FOR(i, 1, n) {
        pq.push({ v[i].second.z - v[i - 1].second.z, {v[i].first, v[i - 1].first} });
    }

    FOR(i, 0, 100001) {
        parent[i] = i;
    }

    ll ans = 0;
    // cout << pq.size() << endl;
    while (!pq.empty()) {
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        int cost = pq.top().first;
        pq.pop();

        if (!Same(a, b)) {
            ans += cost;
            Union(a, b);
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}