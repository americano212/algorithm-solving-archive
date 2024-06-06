#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2147483647
#define ll long long
#define pll pair<ll, ll>
#define matrix vector<vector<ll>>
#define lcm(a, b) a *b / gcd(a, b)
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1000000007LL;

using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int n, m;

vector<vector<int>> ans;

void recur(vector<int>& v, vector<int>& target, vector<bool>& visit) {
    vector<int> tmp;
    if (v.size() == m) {
        FOR(i, 0, m) tmp.push_back(v[i]);
        ans.push_back(tmp);
        return;
    }

    FOR(i, 0, n) {
        if (visit[i]) continue;
        v.push_back(target[i]);
        visit[i] = true;
        recur(v, target, visit);
        visit[i] = false;
        v.pop_back();
    }
}

void solve() {
    cin >> n >> m;

    vector<int> v;
    vector<int> target(n);
    vector<bool> visit(n + 1, false);
    FOR(i, 0, n) {
        cin >> target[i];
    }
    sort(target.begin(), target.end());
    recur(v, target, visit);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    FOR(i, 0, ans.size()) {
        FOR(j, 0, ans[i].size()) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}