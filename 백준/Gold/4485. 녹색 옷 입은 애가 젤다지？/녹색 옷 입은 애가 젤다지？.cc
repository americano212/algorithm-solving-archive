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
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}


void solve() {
    int t = 1;
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;

        matrix mat(n, vector<ll>(n));
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                cin >> mat[i][j];
            }
        }

        matrix distance(n, vector<ll>(n, INF));
        priority_queue<pair<int, pll>, vector<pair<int, pll>>, greater<pair<int, pll>>> pq;
        distance[0][0] = mat[0][0];
        pq.push(make_pair(mat[0][0], make_pair(0, 0)));

        while (!pq.empty()) {
            int now_x = pq.top().second.first;
            int now_y = pq.top().second.second;
            int now_cost = pq.top().first;
            pq.pop();

            if (distance[now_x][now_y] < now_cost) continue;

            FOR(i, 0, 4) {
                int next_x = now_x + dx[i];
                int next_y = now_y + dy[i];
                if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n) {
                    int next_cost = now_cost + mat[next_x][next_y];
                    if (distance[next_x][next_y] > next_cost) {
                        distance[next_x][next_y] = next_cost;
                        pq.push(make_pair(next_cost, make_pair(next_x, next_y)));
                    }
                }
            }
        }
        //FOR(i, 0, n) {
        //    FOR(j, 0, n) {
        //        cout << distance[i][j] << ' ';
        //    }
        //    cout << endl;
        //}

        cout << "Problem " << t << ": ";
        t++;
        cout << distance[n - 1][n - 1] << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}