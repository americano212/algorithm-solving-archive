#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define pll pair<ll, ll>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

using namespace std;



ll init(vector<ll>& v, ll start, ll end) {
    // cout << "?? " << node << ' ' << start << ' ' << end << endl;
    if (start == end) return v[start];

    ll maximum = 0;

    ll mid = (start + end) / 2;

    maximum = max(maximum, init(v, start, mid));
    maximum = max(maximum, init(v, mid + 1, end));
    ll height = min(v[mid], v[mid + 1]);
    maximum = max(maximum, height * 2);
    maximum = max(maximum, v[mid]);
    maximum = max(maximum, v[mid + 1]);

    ll left = mid;
    ll right = mid + 1;
    while (start <= left && right <= end) {
        if (start == left && right < end) {
            right++;
            height = min(height, v[right]);
        }
        else if (start < left && right == end) {
            left--;
            height = min(height, v[left]);
        }
        else if (start == left && right == end) {
            break;
        }
        else if (v[left - 1] > v[right + 1]) {
            left--;
            height = min(height, v[left]);
        }
        else if (v[left - 1] <= v[right + 1]) {
            right++;
            height = min(height, v[right]);
        }
        maximum = max(maximum, height * (right - left + 1));
    }
    return maximum;
}

void solve() {
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<ll> v(n);
        FOR(i, 0, n) {
            cin >> v[i];
        }

        cout << init(v, 0, n - 1) << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}