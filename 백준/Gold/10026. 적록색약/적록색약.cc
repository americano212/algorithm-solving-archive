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
int n;
void bfs(vector<string>& v, vector<vector<bool>>& visit, int start_x, int start_y) {
    queue<pll> qu;
    qu.push({ start_x, start_y });
    visit[start_x][start_y] = true;

    while (!qu.empty()) {
        int now_x = qu.front().first;
        int now_y = qu.front().second;
        qu.pop();
        FOR(idx, 0, 4) {
            int next_x = now_x + dx[idx];
            int next_y = now_y + dy[idx];
            if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n) {
                if (!visit[next_x][next_y] && v[now_x][now_y] == v[next_x][next_y]) {
                    qu.push({ next_x, next_y });
                    visit[next_x][next_y] = true;
                }
            }
        }
    }
}

void solve() {
    
    cin >> n;
    vector<string> v(n);

    FOR(i, 0, n) {
        cin >> v[i];
    }

    vector<vector<bool>> visit(n, vector<bool>(n, false));

    int ans_1 = 0, ans_2 = 0;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            if (!visit[i][j]) {
                bfs(v, visit, i, j);
                ans_1++;
            }

        }
    }
    visit.assign(n, vector<bool>(n, false));

    vector<string> no_green_v(n);
    FOR(i, 0, n) {
        string s;
        FOR(j, 0, n) {
            if (v[i][j] == 'G') {
                s += 'R';
            }
            else {
                s += v[i][j];
            }
        }
        no_green_v[i] = s;
    }
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            if (!visit[i][j]) {
                bfs(no_green_v, visit, i, j);
                ans_2++;
            }

        }
    }
    cout << ans_1 << ' ' << ans_2 << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}