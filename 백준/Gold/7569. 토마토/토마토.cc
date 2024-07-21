#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pllp pair<ll, pll>
#define pff pair<float, float>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
#define all(v) v.begin(), v.end()
#define btw(x,a,b) a<=x && x<b
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dx6[6] = { 1,-1,0,0,0,0 };
int dy6[6] = { 0,0,1,-1,0,0 };
int dz6[6] = { 0,0,0,0,1,-1 };
int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

struct EDGE {
    ll start;
    ll end;
    ll cost;
};

//struct CMP {
//    bool operator() (INFO a, INFO b) {
//        return a.cost > b.cost;
//    }
//};

int m, n, h;

void solve() {
    cin >> m >> n >> h;
    vector<matrix> v(h, matrix(n, vector<ll>(m)));
    vector<matrix> visit(h, matrix(n, vector<ll>(m, -1)));

    queue<vector<int>> qu;

    int tomato_cnt = 0;
    FOR(i, 0, h) {
        FOR(j, 0, n) {
            FOR(k, 0, m) {
                cin >> v[i][j][k];
                if (v[i][j][k] == 1) {
                    qu.push({ i,j,k });
                    visit[i][j][k] = 0;
                }
                if (v[i][j][k] == -1)tomato_cnt++;
            }
        }
    }
    

    while (!qu.empty()) {
        int x = qu.front()[2];
        int y = qu.front()[1];
        int z = qu.front()[0];
        qu.pop();
        FOR(idx, 0, 6) {
            int nx = x + dx6[idx];
            int ny = y + dy6[idx];
            int nz = z + dz6[idx];
            if(btw(nx, 0, m) && btw(ny, 0, n) && btw(nz, 0, h)) {
                // cout << "?? " << endl;
                if (visit[nz][ny][nx] == -1 && v[nz][ny][nx] == 0) {
                    visit[nz][ny][nx] = visit[z][y][x] + 1;
                    qu.push({ nz,ny,nx });
                }
            }
        }
    }

    ll not_visit_cnt = 0;
    ll ans = 0;

    FOR(i, 0, h) {
        FOR(j, 0, n) {
            FOR(k, 0, m) {
                //cout << visit[i][j][k] << ' ';
                if (visit[i][j][k] == -1) not_visit_cnt++;
                ans = max(ans, visit[i][j][k]);
            }
            //cout << endl;
        }
    }

    if (tomato_cnt != not_visit_cnt) ans = -1;

    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}