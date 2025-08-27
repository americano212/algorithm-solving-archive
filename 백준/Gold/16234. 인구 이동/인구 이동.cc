#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n'
#define INF 2'147'483'647LL
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

const ll mod = 1234567891LL;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int dx6[6] = { 1,-1,0,0,0,0 };
int dy6[6] = { 0,0,1,-1,0,0 };
int dz6[6] = { 0,0,0,0,1,-1 };
int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

struct EDGE { ll start; ll end; ll cost; };
struct DOT3 { ll x; ll y; ll z; };
struct NODE { ll max_value; int max_index; ll now_value; int now_node; };
struct ITEM { bool isNum; int num = 0; char bracket = ' '; };
struct MOVE { int x; int y; int time; };


void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    matrix mat(n, vector<ll>(n, 0));
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cin >> mat[i][j];
        }
    }
    
    int ans = 0;

    bool flag = true;
    while (flag) {
        flag = false;
        

        queue<pii> qu;
        matrix visited(n, vector<ll>(n, 0));
        
        matrix next_mat = mat;

        FOR(i, 0, n) {
            FOR(j, 0, n) {
                queue<pii> people_trace;
                int people_sum = 0;
                if (visited[i][j] == 0) {
                    qu.push({ i,j });
                    visited[i][j] = 1;

                    while (!qu.empty()) {
                        int x = qu.front().first;
                        int y = qu.front().second;
                        qu.pop();
                        people_trace.push({ x,y });
                        people_sum += mat[x][y];

                        FOR(idx, 0, 4) {
                            int nx = x + dx[idx];
                            int ny = y + dy[idx];
                            if (btw(nx, 0, n) && btw(ny, 0, n)) {
                                if (visited[nx][ny] == 0 && btw(abs(mat[x][y] - mat[nx][ny]), l, r+1)) {
                                    qu.push({ nx,ny });
                                    visited[nx][ny] = 1;
                                }
                            }
                        }
                    }
                }

                if (people_trace.size() <= 1) continue;
                int people_avg = people_sum / people_trace.size();
                // cout << people_sum << ' ' << people_trace.size() << endl;
                while (!people_trace.empty()) {
                    int tx = people_trace.front().first;
                    int ty = people_trace.front().second;
                    people_trace.pop();
                    next_mat[tx][ty] = people_avg;
                    flag = true;
                }
            }
        }
        mat = next_mat;
        //FOR(i, 0, n) {
        //    FOR(j, 0, n) {
        //        cout << mat[i][j] << ' ';
        //    }
        //    cout << endl;
        //}
        ans++;
    }
    cout << ans - 1 << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}