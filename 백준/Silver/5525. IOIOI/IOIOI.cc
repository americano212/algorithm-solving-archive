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
    int n, m;
    cin >> n;
    cin >> m;
    string s; 
    cin >> s;
    vector<int> length_ioi;

    bool i_flag = false;
    int last_i = -1;

    int idx = 0;
    int temp = 0;

    while (idx < m) {
        if (i_flag == false) {
            if (s[idx] == 'I') {
                i_flag = true;
                temp = 0;
            }
            else {
                idx++;
            }            
        }
        else {
            if (idx + 2 < m) {
                if (s[idx + 1] == 'O' && s[idx + 2] == 'I') {
                    temp++;
                    idx += 2;
                }
                else {
                    length_ioi.push_back(temp);
                    i_flag = false;
                    temp = 0;
                    idx++;
                }
            }
            else {
                length_ioi.push_back(temp);
                break;
            }
        }
    }
    ll ans = 0;
    //FOR(i, 0, length_ioi.size()) {
    //    cout << length_ioi[i] << ' ';
    //}
    //cout << endl;
    FOR(i, 0, length_ioi.size()) {
        if (length_ioi[i] >= n) {
            ans += length_ioi[i] - n + 1;
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