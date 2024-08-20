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


ll ccw(vector<pll>& line, pll p3) {
    pll p1 = line[0];
    pll p2 = line[1];

    pll vec1 = { p2.first - p1.first, p2.second - p1.second };
    pll vec2 = { p3.first - p2.first, p3.second - p2.second };
    ll z = vec1.first * vec2.second - vec1.second * vec2.first;
    
    if (z > 0) return 1;
    if (z < 0) return -1;
    return 0;
}

void solve() {
    vector<pll> line1(2);
    vector<pll> line2(2);
    
    FOR(i, 0, 2) {
        cin >> line1[i].first >> line1[i].second;
    }
    FOR(i, 0, 2) {
        cin >> line2[i].first >> line2[i].second;
    }

    sort(all(line1));
    sort(all(line2));

    //FOR(i, 0, 2) {
    //    cout << line1[i].first << ' ' << line1[i].second << ' ';
    //}
    //cout << endl;
    //FOR(i, 0, 2) {
    //    cout << line2[i].first << ' ' << line2[i].second << ' ';
    //}
    //cout << endl;

    // ccw 판정
    int a = ccw(line1, line2[0]) * ccw(line1, line2[1]);
    int b = ccw(line2, line1[0]) * ccw(line2, line1[1]);
    if (a == 0 && b == 0) {
        if (line1[0] <= line2[1] && line2[0] <= line1[1]) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
        return;
    }
    if (a <= 0 && b <= 0) {
        cout << 1 << endl;
        return;
    }
    cout << 0 << endl;
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}