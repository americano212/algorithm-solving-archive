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

int bsearch(vector<int>& v, int l, int r, int value) {
    int mid = (l + r) / 2;
    if (l == r) return mid;
    if (value < v[l]) return l;
    if (value > v[r]) return r;

    if (v[mid] > value) return bsearch(v, l, mid, value);
    else return bsearch(v, mid + 1, r, value);
}

void solve() {
    int n;
    cin >> n;
    vector<pii> pv(n);
    int a, b;
    FOR(i, 0, n) {
        cin >> a >> b;
        pv[i] = { b,a };
    }
    sort(all(pv));
    vector<int> v(n);
    FOR(i, 0, n) {
        v[i] = pv[i].second;
    }

    vector<int> cache;
    cache.push_back(-INF);

    vector<int> dp(n, -1);

    
    FOR(i, 0, n) {
        int target = v[i];
        int pos = bsearch(cache, 0, cache.size() - 1, target);
        // cout << "?? " << target << ' ' << pos << endl;
        // 끝보다 클 때
        if (pos == cache.size() - 1 && cache[pos] < target) {
            cache.push_back(target);
            dp[i] = pos + 1;
        }
        else {
            cache[pos] = target;
            dp[i] = pos;
        }

    }

    ll max_length = cache.size() - 1;
    //FOR(i, 0, n) {
    //    cout << dp[i] << ' ';
    //}
    //cout << endl;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (dp[i] == max_length) {
            max_length--;
        }
        else {
            ans.push_back(pv[i].second);
        }
    }
    sort(all(ans));
    cout << ans.size() << endl;
    FOR(i, 0, ans.size()) {
        cout << ans[i] << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}