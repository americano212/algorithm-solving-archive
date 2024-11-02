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

const ll mod = 9901LL;
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
    ll n;
    cin >> n;
    matrix mat(3, vector<ll>(n, 0));
    mat[0][0] = 1; // 빈칸 빈칸
    mat[1][0] = 1; // 사자 빈칸
    mat[2][0] = 1; // 빈칸 사자

    FOR(i, 1, n) {
        mat[0][i] = (mat[0][i - 1] + mat[1][i - 1] + mat[2][i - 1]) % mod;
        mat[1][i] = (mat[0][i - 1] + mat[2][i - 1]) % mod;
        mat[2][i] = (mat[0][i - 1] + mat[1][i - 1]) % mod;
    }

    //FOR(i, 0, 2) {
    //    FOR(j, 0, n) {
    //        cout << mat[i][j] << ' ';
    //    }
    //    cout << endl;
    //}

    cout << (mat[0][n - 1]+ mat[1][n - 1]+ mat[2][n - 1]) % mod << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}