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

int n, m;

void find_zero(vector<string>& mat, matrix& count_zero, matrix& group, int sx, int sy, int group_id) {
    vector<pll> cache;
    cache.push_back({ sx,sy });

    queue<pll> qu;
    qu.push({ sx,sy });
    mat[sx][sy] = '*';

    while (!qu.empty()) {
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();

        FOR(idx, 0, 4) {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            if (btw(nx, 0, n) && btw(ny, 0, m)) {
                if (mat[nx][ny] == '0') {
                    mat[nx][ny] = '*';
                    cache.push_back({ nx,ny });
                    qu.push({ nx,ny });
                }
            }
        }
    }

    int num = cache.size();
    FOR(i, 0, num) {
        count_zero[cache[i].first][cache[i].second] = num;
        group[cache[i].first][cache[i].second] = group_id;
    }
}

void solve() {
    cin >> n >> m;
    vector<string> mat(n);
    FOR(i, 0, n) {
        cin >> mat[i];
    }

    matrix count_zero(n, vector<ll>(m, 0));
    matrix group(n, vector<ll>(m, 0));
    int group_id = 1;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (mat[i][j] == '0' && count_zero[i][j] == 0) {
                find_zero(mat, count_zero, group, i, j, group_id);
            }
            group_id++;
        }
    }
    vector<int> group_check;

    //FOR(i, 0, n) {
    //    FOR(j, 0, m) {
    //        cout << group[i][j] << ' ';
    //    }
    //    cout << endl;
    //}

    FOR(i, 0, n) {
        FOR(j, 0, m) {
            // cout << count_zero[i][j] << ' ';
            if (mat[i][j] != '1') {
                cout << 0;
            }
            else {
                ll ans = 1;
                group_check.clear();
                FOR(idx, 0, 4) {
                    int ni = i + dx[idx];
                    int nj = j + dy[idx];
                    if (btw(ni, 0, n) && btw(nj, 0, m)) {
                        bool flag = true;
                        FOR(k, 0, group_check.size()) {
                            if (group_check[k] == group[ni][nj]) flag = false;
                        }
                        if (flag) {
                            ans += count_zero[ni][nj];
                            group_check.push_back(group[ni][nj]);
                        }
                    }
                }
                cout << ans % 10;
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