#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647ll
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pllp pair<ll, pll>
#define pff pair<float, float>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
#define all(v) v.begin(), v.end()
#define btw(x,a,b) a<=x && x<b
//ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }
//
//const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
//int dx6[6] = { 1,-1,0,0,0,0 };
//int dy6[6] = { 0,0,1,-1,0,0 };
//int dz6[6] = { 0,0,0,0,1,-1 };
//int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
//int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

//struct EDGE { ll start; ll end; ll cost; };
//struct COORDINATE { ll x; ll y; ll z; };
//
//struct ITEM { bool isNum; int num = 0; char bracket = ' '; };

int mat[101][101];
bool visited[101][101][4];

void solve() {
    int m, n;
    cin >> m >> n;
    //vector<vector<int>> mat(m, vector<int>(n));
    // vector<vector<vector<bool>>> visit(m, vector<vector<bool>>(n, vector<bool>(4, false)));
    FOR(i, 0, m) {
        FOR(j, 0, n) {
            cin >> mat[i][j];
            visited[i][j][0] = false;
            visited[i][j][1] = false;
            visited[i][j][2] = false;
            visited[i][j][3] = false;
        }
    }
    int start_m, start_n, start_d;
    cin >> start_m >> start_n >> start_d;
    int end_m, end_n, end_d;
    cin >> end_m >> end_n >> end_d;

    // 0 동 1 서 2 남 3 북
    start_m -= 1;
    start_n -= 1;
    start_d -= 1;
    end_m -= 1;
    end_n -= 1;
    end_d -= 1;

    // {{방향, cost}, {y,x}} 
    queue<pair<pii, pii>> qu;
    qu.push({ {start_d, 0}, {start_m, start_n} });
    visited[start_m][start_n][start_d] = true;

    while (!qu.empty()) {
        int dir = qu.front().first.first;
        int cost = qu.front().first.second;
        int now_m = qu.front().second.first;
        int now_n = qu.front().second.second;
        visited[now_m][now_n][dir] = true;
        qu.pop();

        if (now_m == end_m && now_n == end_n && dir == end_d) {
            cout << cost << endl;
            return;
        }

        FOR(move, 1, 4) {
            int next_m = now_m + dy[dir] * move;
            int next_n = now_n + dx[dir] * move;
            if (btw(next_m, 0, m) && btw(next_n, 0, n)) {
                if (mat[next_m][next_n] == 1) break;
                if (visited[next_m][next_n][dir] == false) {
                    qu.push({ {dir, cost + 1},{next_m,next_n} });
                    visited[next_m][next_n][dir] = true;
                }
            }
        }
        if (dir <= 1) {
            FOR(idx, 2, 4) {
                if (visited[now_m][now_n][idx] == false) {
                    qu.push({ {idx, cost + 1},{now_m,now_n} });
                    visited[now_m][now_n][idx] = true;
                }
            }
        }
        else {
            FOR(idx, 0, 2) {
                if (visited[now_m][now_n][idx] == false) {
                    qu.push({ {idx, cost + 1},{now_m,now_n} });
                    visited[now_m][now_n][idx] = true;
                }
            }
        }

    }

}



int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}