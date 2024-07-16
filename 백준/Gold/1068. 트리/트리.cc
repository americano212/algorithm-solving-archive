#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define pll pair<ll, ll>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1};
using namespace std;

vector<int> max_depth(51, 0);

int find(vector<int>& parent, int x, int depth) {
    max_depth[x] = max(max_depth[x], depth);
    if (parent[x] == -1) return x;
    if (parent[x] == -2) return -2;


    return find(parent, parent[x], depth + 1);
}

void solve() {
    int n;
    cin >> n;
    vector<int> parent(n);
    FOR(i, 0, n) {
        cin >> parent[i];
    }
    int m;
    cin >> m;
    parent[m] = -2;
    vector<int> check(n);
    FOR(node, 0, n) {
        check[node] = find(parent, node, 0);
    }
    //FOR(i, 0, n) {
    //    cout << max_depth[i]<<' ';
    //}
    //cout << endl;
    int ans = 0;
    FOR(i, 0, n) {
        if (max_depth[i] == 0 && check[i] != -2) ans++;
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