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
int dy[4] = { 0,0,1,-1 };

using namespace std;

ll swap_cnt = 0;

void bubble(vector<int>& v, vector<vector<int>>& tree, int node, int start, int end) {
    // cout << "?? " << node << ' ' << start << ' ' << end << endl;
    if (start == end) {
        tree[node].push_back(v[start]);
        return;
    }
    int mid = (start + end) / 2;
    bubble(v, tree, 2 * node, start, mid);
    bubble(v, tree, 2 * node + 1, mid + 1, end);

    int left_pivot = 0;
    int right_pivot = 0;

    int left_size = tree[2 * node].size();
    int right_size = tree[2 * node + 1].size();

    while (left_pivot <= left_size && right_pivot <= right_size) {
        if (left_pivot != left_size && right_pivot == right_size) {
            tree[node].push_back(tree[2 * node][left_pivot]);
            left_pivot++;
        }
        else if (left_pivot == left_size && right_pivot != right_size) {
            tree[node].push_back(tree[2 * node + 1][right_pivot]);
            right_pivot++;
        }
        else if (left_pivot == left_size && right_pivot == right_size) {
            break;
        } 
        else if (tree[2 * node][left_pivot] <= tree[2 * node + 1][right_pivot]) {
            tree[node].push_back(tree[2 * node][left_pivot]);
            left_pivot++;
        }
        else if (tree[2 * node][left_pivot] > tree[2 * node + 1][right_pivot]) {
            swap_cnt += left_size - left_pivot;
            tree[node].push_back(tree[2 * node + 1][right_pivot]);
            right_pivot++;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    FOR(i, 0, n) {
        cin >> v[i];
    }
    vector<vector<int>> tree(4 * n);
    bubble(v, tree, 1, 0, n - 1);
    cout << swap_cnt << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}