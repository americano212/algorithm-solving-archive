#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
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

const ll mod = 1'000'000'007LL;
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
struct NODE { int a; int b; int c; };
struct ITEM { bool isNum; int num = 0; char bracket = ' '; };
struct MOVE { int x; int y; int time; };

void solve() {
    vector<vector<vector<bool>>> visited(201, vector<vector<bool>>(201, vector<bool>(201, false)));
    int a, b, c;
    cin >> a >> b >> c;

    visited[0][0][c] = true;
    queue<NODE> qu;
    qu.push({ 0,0,c });

    while (!qu.empty()) {
        NODE now = qu.front();
        qu.pop();
        int temp = 0;
        if (now.a != 0) {
            temp = min(b - now.b, now.a);
            if (!visited[now.a - temp][now.b + temp][now.c]) {
                visited[now.a - temp][now.b + temp][now.c] = true;
                qu.push({ now.a - temp,now.b + temp,now.c });
            }

            temp = min(c - now.c, now.a);
            if (!visited[now.a - temp][now.b][now.c + temp]) {
                visited[now.a - temp][now.b][now.c + temp] = true;
                qu.push({ now.a - temp,now.b,now.c + temp });
            }
        }
        if (now.b != 0) {
            temp = min(a - now.a, now.b);
            if (!visited[now.a + temp][now.b - temp][now.c]) {
                visited[now.a + temp][now.b - temp][now.c] = true;
                qu.push({ now.a + temp,now.b - temp,now.c });
            }

            temp = min(c - now.c, now.b);
            if (!visited[now.a][now.b - temp][now.c + temp]) {
                visited[now.a][now.b - temp][now.c + temp] = true;
                qu.push({ now.a,now.b - temp,now.c + temp });
            }
        }
        if (now.c != 0) {
            temp = min(a - now.a, now.c);
            if (!visited[now.a + temp][now.b][now.c - temp]) {
                visited[now.a + temp][now.b][now.c - temp] = true;
                qu.push({ now.a + temp,now.b,now.c - temp });
            }

            temp = min(b - now.b, now.c);
            if (!visited[now.a][now.b + temp][now.c - temp]) {
                visited[now.a][now.b + temp][now.c - temp] = true;
                qu.push({ now.a,now.b + temp,now.c - temp });
            }
        }
    }
    vector<bool> ans(201, false);
    FOR(i, 0, 201) {
        FOR(j, 0, 201) {
            if (visited[0][i][j]) {
                ans[j] = true;
            }
        }
    }

    FOR(i, 0, 201) {
        if (ans[i]) {
            cout << i << ' ';
        }
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}