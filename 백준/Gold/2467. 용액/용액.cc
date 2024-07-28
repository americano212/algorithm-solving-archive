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

int binary_search(int start, int end, int target, vector<int>& v) {
    if (start == end) return v[start];

    int mid = (start + end) / 2;
    // mid에 더 가까울 때
    if (abs(v[mid] - target) < abs(v[mid + 1] - target)) {
        return binary_search(start, mid, target, v);
    }
    else {
        return binary_search(mid + 1, end, target, v);
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    FOR(i, 0, n) {
        cin >> v[i];
    }
    int min_ans = INF;
    vector<int> ans(2, 0);

    FOR(idx, 0, n - 1) {
        int result = binary_search(idx + 1, n - 1, -v[idx], v);
        if (min_ans > abs(result + v[idx])) {
            min_ans = abs(result + v[idx]);
            ans[0] = result;
            ans[1] = v[idx];
        }
    }
    sort(all(ans));
    cout << ans[0] << ' ' << ans[1] << endl;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    //cin >> tc;
    while (tc--)solve();

    return 0;
}