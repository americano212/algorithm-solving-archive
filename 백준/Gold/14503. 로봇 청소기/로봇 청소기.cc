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
struct COORDINATE { ll x; ll y; ll z; };

struct ITEM { bool isNum; int num = 0; char bracket = ' '; };

struct NODE { int x; int y; int dir; };

void solve() {
    int n, m;
    cin >> n >> m;
    int r, c, d;
    cin >> r >> c >> d;

    matrix mat(n, vector<ll>(m));

    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> mat[i][j];
        }
    }

    queue<NODE> qu;
    qu.push({ r,c,d });

    int ans = 0;
    while (!qu.empty()) {
        NODE now = qu.front();
        if (mat[now.x][now.y] == 0) {
            mat[now.x][now.y] = 2;
            ans++;
        }
        // cout << " ?? " << now.x << ' ' << now.y << ' ' << now.dir << endl;
         
        qu.pop();

        bool flag = true;
        FOR(i, 0, 4) {
            NODE next = now;
            next.dir = (now.dir + 3 - i) % 4;
            next.x += dx[next.dir];
            next.y += dy[next.dir];
            
            if (btw(next.x, 0, n) && btw(next.y, 0, m)) {
                if (!mat[next.x][next.y]) {
                    qu.push(next);
                    flag = false;
                    break;
                }
            }
        }

        if (flag) {
            NODE back = now;
            back.x += dx[(now.dir + 2) % 4];
            back.y += dy[(now.dir + 2) % 4];
            if (btw(back.x, 0, n) && btw(back.y, 0, m)) {
                if (mat[back.x][back.y] != 1) {
                    qu.push(back);
                }
            }
            else {
                break;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}