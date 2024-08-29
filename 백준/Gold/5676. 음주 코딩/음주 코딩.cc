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

int init(vector<int>& v, vector<int>& tree, int node, int start, int end) {
    if (start == end) return tree[node] = v[start];
    int mid = (start + end) / 2;
    int a = init(v, tree, 2 * node, start, mid);
    int b = init(v, tree, 2 * node + 1, mid + 1, end);
    return tree[node] = a * b;
}

void update(vector<int>& v, vector<int>& tree, int node, int start, int end, int index) {
    if (index < start || end < index) return;

    if (start == end) {
        tree[node] = v[index]; return;
    }
    //cout << "!!" << endl;
    int mid = (start + end) / 2;
    update(v, tree, 2 * node, start, mid, index);
    update(v, tree, 2 * node + 1, mid + 1, end, index);

    tree[node] = tree[2 * node] * tree[2 * node + 1];
}

int query(vector<int>& tree, int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 1;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    int a = query(tree, 2 * node, start, mid, left, right);
    int b = query(tree, 2 * node + 1, mid + 1, end, left, right);
    return a * b;
}

void solve() {
    int n, k;
    while (cin >> n >> k) {
        vector<int> v(n + 1);
        int temp;
        FOR(i, 0, n) {
            cin >> temp;
            if (temp == 0) v[i] = 0;
            if (temp > 0) v[i] = 1;
            if (temp < 0) v[i] = -1;
        }

        vector<int> tree(4 * n, 0);
        init(v, tree, 1, 0, n - 1);

        char flag;
        int a, b;
        FOR(_, 0, k) {
            cin >> flag >> a >> b;
            if (flag == 'C') {
                if (b > 0) b = 1;
                else if (b < 0) b = -1;
                else b = 0;

                v[a - 1] = b;
                update(v, tree, 1, 0, n - 1, a - 1);
                /*FOR(i, 1, 15) {
                    cout << tree[i] << ' ';
                }
                cout << endl;*/
            }
            if (flag == 'P') {
                int result = query(tree, 1, 0, n - 1, a - 1, b - 1);
                if (result > 0) cout << '+';
                if (result < 0) cout << '-';
                if (result == 0) cout << '0';
            }
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}