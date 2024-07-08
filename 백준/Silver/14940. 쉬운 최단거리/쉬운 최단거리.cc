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


void solve() {
    int n, m;
    cin >> n >> m;
    matrix mat(n, vector<ll>(m));
    int start_x, start_y;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> mat[i][j];
            if (mat[i][j] == 2) {
                start_y = i;
                start_x = j;
            }
        }
    }

    matrix visit(n, vector<ll>(m, -1));

    queue<pair<pll, int>> qu;
    qu.push(make_pair(make_pair(start_y, start_x), 0));
    visit[start_y][start_x] = 0;

    while (!qu.empty()) {
        int now_y = qu.front().first.first;
        int now_x = qu.front().first.second;
        int now_cost = qu.front().second;
        qu.pop();

        FOR(i, 0, 4) {
            int next_y = now_y + dy[i];
            int next_x = now_x + dx[i];
            if (0 <= next_y && next_y < n && 0 <= next_x && next_x < m) {
                if (visit[next_y][next_x] == -1 && mat[next_y][next_x] != 0) {
                    visit[next_y][next_x] = now_cost + 1;
                    qu.push(make_pair(make_pair(next_y, next_x), now_cost + 1));
                }
            }
        }
    }
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (visit[i][j] == -1 && mat[i][j] == 0) {
                visit[i][j] = 0;
            }
            cout << visit[i][j] << ' ';
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