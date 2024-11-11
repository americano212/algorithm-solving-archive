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

bool compare(string& s1, string& s2) {
    if (s1.size() == s2.size()) {
        int num1 = 0;
        int num2 = 0;
        FOR(i, 0, s1.size()) {
            if ('0' <= s1[i] && s1[i] <= '9') {
                num1 += (int)(s1[i] - '0');
            }
        }
        FOR(i, 0, s2.size()) {
            if ('0' <= s2[i] && s2[i] <= '9') {
                num2 += (int)(s2[i] - '0');
            }
        }
        if (num1 == num2) {
            return s1 < s2;
        }
        else {
            return num1 < num2;
        }
    }
    else {
        return s1.size() < s2.size();
    }
}

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    FOR(i, 0, n) cin >> v[i];
    sort(all(v), compare);
    FOR(i, 0, n) {
        cout << v[i] << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}