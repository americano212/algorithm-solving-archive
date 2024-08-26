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
struct DOT3 { ll x; ll y; ll z; };
struct NODE { int x; int y; int dir; };
struct ITEM { bool isNum; int num = 0; char bracket = ' '; };

void make_tree(vector<int>& parent_list, matrix& mat, matrix& child_list, int node, int parent) {
    parent_list[node] = parent;
    FOR(idx, 0, mat[node].size()) {
        int child = mat[node][idx];
        if (child != parent) {
            child_list[node].push_back(child);
            make_tree(parent_list, mat, child_list, child, node);
        }
    }
}

void calcSubtree(vector<int>& subtree_cnt, matrix& child_list, int node) {
    subtree_cnt[node] = 1;
    FOR(i, 0, child_list[node].size()) {
        int child = child_list[node][i];
        calcSubtree(subtree_cnt, child_list, child);
        subtree_cnt[node] += subtree_cnt[child];
    }
}

void solve() {
    int n, r, q;
    cin >> n >> r >> q;
    matrix mat(n + 1);
    FOR(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    vector<int> parent_list(n + 1, 0);
    matrix child_list(n + 1);
    make_tree(parent_list, mat, child_list, r, -1);
    //FOR(i, 1, n + 1) {
    //    cout << parent_list[i] << ' ';
    //}
    //cout << endl;
    vector<int> subtree_cnt(n + 1, 0);
    calcSubtree(subtree_cnt, child_list, r);
    //FOR(i, 1, n + 1) {
    //    cout << subtree_cnt[i] << ' ';
    //}
    //cout << endl;
    FOR(_, 0, q) {
        int node;
        cin >> node;
        cout << subtree_cnt[node] << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}