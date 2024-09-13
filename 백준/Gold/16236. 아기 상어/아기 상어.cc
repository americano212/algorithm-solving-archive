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
int dy[4] = { 0,-1,0,1 };
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
struct MOVE { int x; int y; int time; };

bool compare(const MOVE& m1, const MOVE& m2) {
    if (m1.time == m2.time) {
        if (m1.x == m2.x) {
            return m1.y < m2.y;
        }
        else {
            return m1.x < m2.x;
        }
    }
    else {
        return m1.time < m2.time;
    }
}

int n;

MOVE scan_fish(matrix& mat, pii& shark_pos, int shark_sz) {
    queue<MOVE> qu;
    qu.push({ shark_pos.first, shark_pos.second, 0 });
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[shark_pos.first][shark_pos.second] = true;

    vector<MOVE> target;

    while (!qu.empty()) {
        int x = qu.front().x;
        int y = qu.front().y;
        int time = qu.front().time;
        qu.pop();

        FOR(idx, 0, 4) {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            if (btw(nx, 0, n) && btw(ny, 0, n)) {
                if (visited[nx][ny] == true) continue;

                int ntime = time + 1;
                if (0 < mat[nx][ny] && mat[nx][ny] < shark_sz) {
                    target.push_back({ nx,ny,ntime });
                }
                if (mat[nx][ny] == 0 || mat[nx][ny] == shark_sz) {
                    visited[nx][ny] = true;
                    qu.push({ nx,ny,ntime });
                }
            }
        }
    }
    sort(target.begin(), target.end(), compare);

    if (target.empty()) return { -1,-1,-1 };
    else return target[0];
}

void solve() {
    cin >> n;
    matrix mat(n, vector<ll>(n));

    pii shark_pos;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cin >> mat[i][j];
            if (mat[i][j] == 9) {
                shark_pos = { i,j };
                mat[i][j] = 0;
            }
        }
    }

    int shark_sz = 2;
    int eat_fish = 0;

    ll total_time = 0;

    while (true) {
        MOVE scan_result = scan_fish(mat, shark_pos, shark_sz);
        if (scan_result.time == -1) break;

        shark_pos.first = scan_result.x;
        shark_pos.second = scan_result.y;
        mat[scan_result.x][scan_result.y] = 0;
        eat_fish++;
        if (eat_fish == shark_sz) {
            shark_sz++;
            eat_fish = 0;
        }
        total_time += scan_result.time;
    }

    cout << total_time << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}