#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pllp pair<ll, pll>
#define pff pair<float, float>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
#define all(v) v.begin(), v.end()
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

struct EDGE {
    ll start;
    ll end;
    ll cost;
};

//struct CMP {
//    bool operator() (INFO a, INFO b) {
//        return a.cost > b.cost;
//    }
//};

void solve() {
    int n, m, w;
    cin >> n >> m >> w;
    vector<EDGE> mat(n + 1);
    int a, b, c;
    FOR(i, 0, m) {
        cin >> a >> b >> c;
        mat.push_back({ a,b,c });
        mat.push_back({ b,a,c });
    }
    FOR(i, 0, w) {
        cin >> a >> b >> c;
        mat.push_back({ a,b,-c });
    }

    bool flag = false;

    vector<ll> distance(n + 1, INF);
    distance[1] = 0;
    FOR(i, 0, n) {
        FOR(idx, 0, mat.size()) {
            int start = mat[idx].start;
            int end = mat[idx].end;
            int cost = mat[idx].cost;

            if (distance[end] > distance[start] + cost) {
                distance[end] = distance[start] + cost;
                if (i == n - 1) {
                    flag = true;
                }
            }

        }
        //FOR(i, 1, n + 1) {
        //    cout << distance[i] << ' ';
        //}
        //cout << endl;
    }
    if (flag) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    cin >> tc;
    while (tc--)solve();

    return 0;
}