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

void prt(int x) {
    if (x % 3 == 0 && x % 5 == 0) {
        cout << "FizzBuzz" << endl;
        return;
    }
    if (x % 3 == 0) {
        cout << "Fizz" << endl;
        return;
    }
    if (x % 5 == 0) {
        cout << "Buzz" << endl;
        return;
    }
    cout << x << endl;
}

void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    if (a[0] != 'F' && a[0] != 'B') {
        prt(stoi(a) + 3);
        return;
    }
    if (b[0] != 'F' && b[0] != 'B') {
        prt(stoi(b) + 2);
        return;
    }
    if (c[0] != 'F' && c[0] != 'B') {
        prt(stoi(c) + 1);
        return;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}