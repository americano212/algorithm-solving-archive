#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2147483647
#define ll long long
#define pll pair<ll, ll>
#define matrix vector<vector<ll>>
#define lcm(a, b) a *b / gcd(a, b)
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1000000007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int find(int x, vector<int>& parent) {
    if (x == parent[x]) return x;

    return parent[x] = find(parent[x], parent);
}

void merge(int x, int y, vector<int>& parent) {
    int a = find(x, parent);
    int b = find(y, parent);
    if (a == b) return;

    parent[b] = a;
}

bool isUnion(int x, int y, vector<int>& parent) {
    int a = find(x, parent);
    int b = find(y, parent);

    return (a == b) ? true : false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int check, a, b;

    vector<int> parent(n+1);
    FOR(i, 0, n + 1) {
        parent[i] = i;
    }

    FOR(_, 0, m) {
        cin >> check >> a >> b;
        if (check) {
            bool temp = isUnion(a, b, parent);
            if (temp) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else {
            merge(a, b, parent);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();

    return 0;
}