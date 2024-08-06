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

struct EDGE { ll start; ll end; ll cost; };
struct COORDINATE { ll x; ll y; ll z; };

struct ITEM { bool isNum; int num = 0; char bracket = ' '; };


void solve() {
    int n;
    cin >> n;
    matrix mat(n, vector<ll>(3, 0));
    FOR(i, 0, n) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }
    
    ll ans = INF * INF;

    // 첫집 red 고정
    matrix first_red(n, vector<ll>(3, 0));
    first_red = mat;
    first_red[0] = { mat[0][0],INF,INF };

    FOR(i, 1, n) {
        first_red[i][0] += min(first_red[i - 1][1], first_red[i - 1][2]);
        first_red[i][1] += min(first_red[i - 1][0], first_red[i - 1][2]);
        first_red[i][2] += min(first_red[i - 1][0], first_red[i - 1][1]);
    }
    
    ans = min(ans, first_red[n - 1][1]);
    ans = min(ans, first_red[n - 1][2]);
    //cout << "?? " << ans << endl;

    // 첫집 green 고정
    matrix first_green(n, vector<ll>(3, 0));
    first_green = mat;
    first_green[0] = { INF,mat[0][1],INF };

    FOR(i, 1, n) {
        first_green[i][0] += min(first_green[i - 1][1], first_green[i - 1][2]);
        first_green[i][1] += min(first_green[i - 1][0], first_green[i - 1][2]);
        first_green[i][2] += min(first_green[i - 1][0], first_green[i - 1][1]);
    }
    
    ans = min(ans, first_green[n - 1][0]);
    ans = min(ans, first_green[n - 1][2]);
    //cout << "?? " << ans << endl;

    // 첫집 blue 고정
    matrix first_blue(n, vector<ll>(3, 0));
    first_blue = mat;
    first_blue[0] = { INF,INF,mat[0][2] };

    FOR(i, 1, n) {
        first_blue[i][0] += min(first_blue[i - 1][1], first_blue[i - 1][2]);
        first_blue[i][1] += min(first_blue[i - 1][0], first_blue[i - 1][2]);
        first_blue[i][2] += min(first_blue[i - 1][0], first_blue[i - 1][1]);
    }

    //FOR(i, 0, n) {
    //    FOR(j, 0, 3) {
    //        cout << first_blue[i][j] << ' ';
    //    }
    //    cout << endl;
    //}
    ans = min(ans, first_blue[n - 1][0]);
    ans = min(ans, first_blue[n - 1][1]);
    //cout << "?? " << ans << endl;
    cout << ans << endl;
}



int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}