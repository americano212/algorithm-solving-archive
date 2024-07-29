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

string bfs(int a, int b) {
    vector<bool> visit(10001, false);

    queue<pair<int, string>> qu;
    qu.push({ a, "" });
    visit[a] = true;

    while (!qu.empty()) {
        int now = qu.front().first;
        string s = qu.front().second;
        qu.pop();

        if (now == b) return s;

        int case_D = 2 * now % 10000;
        if (!visit[case_D]) {
            visit[case_D] = true;
            qu.push({ case_D, s + 'D' });
        }

        int case_S = (now == 0) ? 9999 : now - 1;
        if (!visit[case_S]) {
            visit[case_S] = true;
            qu.push({ case_S ,s + 'S' });
        }

        int temp = now;
        vector<int> temp_vec(4, 0);
        int idx = 0;
        while (idx < 4) {
            temp_vec[idx] = temp % 10;
            idx++;
            temp /= 10;
        }
        
        int case_L = temp_vec[2] * 1000 + temp_vec[1] * 100 + temp_vec[0] * 10 + temp_vec[3];
        if (!visit[case_L]) {
            visit[case_L] = true;
            qu.push({ case_L ,s + 'L' });
        }

        

        int case_R = temp_vec[0] * 1000 + temp_vec[3] * 100 + temp_vec[2] * 10 + temp_vec[1];
        if (!visit[case_R]) {
            visit[case_R] = true;
            qu.push({ case_R ,s + 'R' });
        }
    }
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << bfs(a, b) << endl;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    cin >> tc;
    while (tc--)solve();

    return 0;
}