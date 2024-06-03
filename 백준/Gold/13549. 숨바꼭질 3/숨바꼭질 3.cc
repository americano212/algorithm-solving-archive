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

    vector<int> visit_time(100001, -1);

    queue<pll> qu;

    qu.push(make_pair(n, 0));
    visit_time[n] = 0;

    int node, time;
    pll tmp;
    while (!qu.empty()) {
        tmp = qu.front();
        qu.pop();
        node = tmp.first;
        time = tmp.second;


        int choose[3] = { node - 1 ,node + 1, 2 * node };
        int need_time[3] = { 1,1,0 };

        FOR(i, 0, 3) {
            int next_node = choose[i];
            if (0 <= next_node && next_node <= 100000) {
                if (visit_time[next_node] == -1) {
                    visit_time[next_node] = time + need_time[i];
                    qu.push(make_pair(next_node, time + need_time[i]));
                }
                else {
                    if (visit_time[next_node] > time + need_time[i]) {
                        visit_time[next_node] = time + need_time[i];
                        qu.push(make_pair(next_node, time + need_time[i]));
                    }
                }
            }
        }
    }

    cout << visit_time[k] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}