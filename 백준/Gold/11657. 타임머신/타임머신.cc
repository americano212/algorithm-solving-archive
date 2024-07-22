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
    vector<EDGE> v(m);

    vector<int> distance(n + 1, INF);
    distance[1] = 0;
    int a, b, c;
    FOR(i, 0, m) {
        cin >> a >> b >> c;
        v[i] = { a,b,c };
        if (a == 1) distance[b] = c;
    }

    FOR(node, 1, n + 1) {
        FOR(edge, 0, m) {
            if (distance[v[edge].start] == INF) continue;
            if (distance[v[edge].start] + v[edge].cost < distance[v[edge].end]) {
                if (node == n) {
                    cout << -1 << endl;
                    return;
                }
                distance[v[edge].end] = distance[v[edge].start] + v[edge].cost;
            }
        }
        //FOR(i, 1, n + 1) {
        //    cout << distance[i] << ' ';
        //}
        //cout << endl;
    }
    FOR(i, 2, n + 1) {
        if (distance[i] == INF) {
            cout << -1 << endl;
        }
        else {
            cout << distance[i] << endl;
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