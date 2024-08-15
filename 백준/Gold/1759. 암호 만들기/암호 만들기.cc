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

int n, m;

void dfs(vector<char>& v, string s, int vowel, int consonant, int last_idx) {
    if (s.size() == n) {
        if (vowel >= 1 && consonant >= 2) {
            cout << s << endl;
        }
        return;
    }

    FOR(idx, last_idx + 1, v.size()) {
        char target = v[idx];
        if (target == 'a' || target == 'e' || target == 'i' || target == 'o' || target == 'u') {
            dfs(v, s + target, vowel + 1, consonant, idx);
        }
        else {
            dfs(v, s + target, vowel, consonant + 1, idx);
        }
    }
}

void solve() {
    cin >> n >> m;
    vector<char> v(m);
    FOR(i, 0, m) {
        cin >> v[i];
    }

    sort(all(v));

    dfs(v, "", 0, 0, -1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}