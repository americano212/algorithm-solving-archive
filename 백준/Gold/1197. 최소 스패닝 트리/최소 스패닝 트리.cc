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
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
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

int Find(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent, parent[x]);
}

void Union(vector<int>& parent, int x, int y) {
    int a = Find(parent, x);
    int b = Find(parent, y);
    if (a < b) {
        parent[a] = b;
    }
    else {
        parent[b] = a;
    }
}

bool Same(vector<int>& parent, int x, int y) {
    int a = Find(parent, x);
    int b = Find(parent, y);
    
    return (a == b) ? true : false;
}

void solve() {
    int n, m;
    cin >> n >> m;

    priority_queue<pllp, vector<pllp>, greater<pllp>> pq;

    int a, b, c;
    FOR(i, 0, m) {
        cin >> a >> b >> c;
        pq.push({ c,{a,b} });
    }

    vector<int> parent(n + 1);
    FOR(i, 0, n + 1) {
        parent[i] = i;
    }

    ll ans = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (!Same(parent, x, y)) {
            ans += cost;
            Union(parent, x, y);
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