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


void solve() {
    int n;
    cin >> n;
    matrix mat(n, vector<ll>(n, 0));


    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cin >> mat[i][j];
        }
    }

    queue<pllp> qu;
    // 0 우 1 하 2 대각
    pii right = { 0, 1 };
    pii down = { 1,0 };
    pii cross = { 1,1 };
    vector<vector<pii>> next = { { right, cross },{ down, cross },{ down, right, cross} };
    qu.push({ 0, { 0,1 } });
    ll ans = 0;
    
    while (!qu.empty()) {
        int now_state = qu.front().first;
        pii now_pos = qu.front().second;
        qu.pop();

        if (now_pos.first == n - 1 && now_pos.second == n - 1) {
            ans++;
            continue;
        }

        FOR(idx, 0, next[now_state].size()) {
            int next_state = 0;
            if (next[now_state][idx] == right) {
                next_state = 0;
            }
            else if (next[now_state][idx] == down) {
                next_state = 1;
            }
            else {
                next_state = 2;
            }
            pii next_pos = now_pos;
            next_pos.first += next[now_state][idx].first;
            next_pos.second += next[now_state][idx].second;

            if (btw(next_pos.first, 0, n) && btw(next_pos.second, 0, n)) {
                if (next_state == 2) {
                    if (mat[next_pos.first][next_pos.second] == 0 && mat[next_pos.first][next_pos.second - 1] == 0 && mat[next_pos.first - 1][next_pos.second] == 0) {
                        qu.push({ next_state, next_pos });
                    }
                }
                else {
                    if (mat[next_pos.first][next_pos.second] == 0) {
                        qu.push({ next_state, next_pos });
                    }
                }
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