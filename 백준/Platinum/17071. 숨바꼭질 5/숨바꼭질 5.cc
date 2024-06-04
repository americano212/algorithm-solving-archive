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

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<bool>> visit(2, vector<bool>(500001, 0));

    queue<pll> qu;

    qu.push(make_pair(n, 0));
    visit[0][n] = true;

    int node, time;
    pll tmp;
    while (!qu.empty()) {
        tmp = qu.front();
        qu.pop();
        node = tmp.first;
        time = tmp.second;


        if (k + time * (time + 1) / 2 > 500000) break;

        // 이미 2*t초 전에 도착한 위치
        if (visit[time % 2][k + time * (time + 1) / 2]) {
            cout << time << endl;
            return;
        }

        int choose[3] = { node - 1 ,node + 1, 2 * node };

        FOR(i, 0, 3) {
            int next_node = choose[i];
            int next_time = time + 1;

            if (0 <= next_node && next_node <= 500000) {
                if (visit[next_time % 2][next_node]) continue;
                visit[next_time % 2][next_node] = true;
                qu.push(make_pair(next_node, next_time));
            }
        }
    }


    cout << -1 << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}