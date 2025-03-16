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
    int n;
    cin >> n;
    vector<int> va(n);
    vector<int> vb(n);

    FOR(i, 0, n) {
        cin >> va[i];
    }
    FOR(i, 0, n) {
        cin >> vb[i];
    }

    bool is_last_win_a = true;
    int max_win_a = 0, max_win_b = 0;
    int win_a = 0, win_b = 0;
    FOR(i, 0, n) {
        if (va[i] == vb[i]) {
            if (is_last_win_a) { // b가 새로 출전
                win_a = 0; win_b = 1;
                is_last_win_a = false;
            }
            else {
                win_a = 1; win_b = 0;
                is_last_win_a = true;
            }
        }
        else {
            if ((va[i] == 1 && vb[i] == 3) || (va[i] == 2 && vb[i] == 1) || (va[i] == 3 && vb[i] == 2)) { // a 승리
                win_a++;
                win_b = 0;
                is_last_win_a = true;
            }
            else {
                win_b++;
                win_a = 0;
                is_last_win_a = false;
            }
        }
        max_win_a = max(max_win_a, win_a);
        max_win_b = max(max_win_b, win_b);
    }
    cout << max(max_win_a, max_win_b) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}