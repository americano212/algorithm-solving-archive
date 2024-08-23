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

const ll mod = 1'000'000'007LL;
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

vector<pii> empty_pos;
matrix mat(9, vector<ll>(9));
vector<bool> visited(10, false);

bool checkSTK(int x, int y) {
    // 가로 체크
    visited.assign(10, false);
    FOR(i, 0, 9) {
        if (mat[x][i] == 0) continue;
        if (visited[mat[x][i]]) return false;
        visited[mat[x][i]] = true;
    }
    // 세로 체크
    visited.assign(10, false);
    FOR(i, 0, 9) {
        if (mat[i][y] == 0) continue;
        if (visited[mat[i][y]]) return false;
        visited[mat[i][y]] = true;
    }

    // ㅁ 체크
    visited.assign(10, false);
    x = (x / 3) * 3;
    y = (y / 3) * 3;
    FOR(i, x, x + 3) {
        FOR(j, y, y + 3) {
            if (mat[i][j] == 0) continue;
            if (visited[mat[i][j]]) return false;
            visited[mat[i][j]] = true;
        }
    }
    return true;
}

void dfs(int index) {
    if (index == empty_pos.size()) {
        FOR(i, 0, 9) {
            FOR(j, 0, 9) {
                cout << mat[i][j] << ' ';
            }
            cout << endl;
        }
        exit(0);
    }

    int x = empty_pos[index].first;
    int y = empty_pos[index].second;

    FOR(num, 1, 10) {
        mat[x][y] = num;
        if (checkSTK(x, y)) {
            dfs(index + 1);
        }
        mat[x][y] = 0;
    }
}

void solve() {
    

    FOR(i, 0, 9) {
        FOR(j, 0, 9) {
            cin >> mat[i][j];
            if (mat[i][j] == 0) empty_pos.push_back({ i,j });
        }
    }

    dfs(0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}