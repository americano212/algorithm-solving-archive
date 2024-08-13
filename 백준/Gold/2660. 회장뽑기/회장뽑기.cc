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

struct ITEM { bool isNum; int num = 0; char bracket = ' '; };

void solve() {
    int n;
    cin >> n;
    matrix graph(n + 1, vector<ll>(n + 1, INF));
    int a, b;
    while (1) {
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    FOR(k, 1, n + 1) {
        graph[k][k] = 0;
        FOR(s, 1, n + 1) {
            FOR(e, 1, n + 1) {
                graph[s][e] = min(graph[s][e], graph[s][k] + graph[k][e]);
            }
        }
    }

    vector<pll> v;

    FOR(s, 1, n + 1) {
        ll max_relation = 0;
        FOR(e, 1, n + 1) {
            max_relation = max(max_relation, graph[s][e]);
        }
        v.push_back({ max_relation, s });
    }
    sort(all(v));
    int relation_ans = v[0].first;
    vector<int> candidate;
    FOR(i, 0, v.size()) {
        if (v[i].first == relation_ans) {
            candidate.push_back(v[i].second);
        }
        else {
            break;
        }
    }

    cout << relation_ans << ' ' << candidate.size() << endl;
    FOR(i, 0, candidate.size()) {
        cout << candidate[i] << ' ';
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