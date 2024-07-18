#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define pll pair<ll, ll>
#define pllp pair<ll, pll>
#define pff pair<float, float>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
#define all(v) v.begin(), v.end()
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1};

int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    matrix mat(n + 1, vector<ll>(n + 1, 0));

    int a, b;
    FOR(i, 0, m) {
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    //FOR(i, 1, n+1) {
    //    FOR(j, 1, n + 1) {
    //        cout << mat[i][j] << ' ';
    //    }
    //    cout << endl;
    //}
    matrix ans(n + 1, vector<ll>(n + 1, INF));

    FOR(start, 1, n + 1) {
        queue<pll> qu;
        qu.push({ start,0 });
        ans[start][start] = 0;

        while (!qu.empty()) {
            int node = qu.front().first;
            int cost = qu.front().second;
            qu.pop();
            FOR(next_node, 1, n + 1) {
                if (mat[node][next_node] == 1) {
                    // cout << "?? " << endl;
                    if (ans[start][next_node] == INF) {
                        ans[start][next_node] = cost + 1;
                        qu.push({ next_node, cost + 1 });
                    }
                }
            }
        }
    }
    int minimum = INF;
    int min_index = 0;

    FOR(i, 1, n + 1) {
        int temp = 0;
        FOR(j, 1, n + 1) {
            temp += ans[i][j];
        }
        if (temp < minimum) {
            minimum = temp;
            min_index = i;
        }
    }
    cout << min_index << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}