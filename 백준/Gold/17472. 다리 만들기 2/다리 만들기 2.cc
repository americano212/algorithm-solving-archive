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

int n, m;

void draw_island(matrix& mat, matrix& island, int a, int b, int tag) {
    queue<pii> qu;
    qu.push({ a,b });

    while (!qu.empty()) {
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();

        FOR(i, 0, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (btw(nx, 0, n) && btw(ny, 0, m)) {
                if (mat[nx][ny] == 1 && island[nx][ny] == 0) {
                    island[nx][ny] = tag;
                    qu.push({ nx,ny });
                }
            }
        }
    }
}

int Find(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent, parent[x]);
}

void Union(vector<int>& parent, int x, int y) {
    int a = Find(parent, x);
    int b = Find(parent, y);
    if (a < b) {
        parent[a] = b;
    }
    else {
        parent[b] = a;
    }
}

bool Same(vector<int>& parent, int x, int y) {
    int a = Find(parent, x);
    int b = Find(parent, y);
    return a == b;
}

void solve() {
    
    cin >> n >> m;
    matrix mat(n, vector<ll>(m));
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> mat[i][j];
        }
    }

    matrix island(n, vector<ll>(m, 0));
    int island_cnt = 0;

    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (mat[i][j] == 1 && island[i][j] == 0) {
                island_cnt++;
                island[i][j] = island_cnt;
                draw_island(mat, island, i, j, island_cnt);
            }
        }
    }

    //cout << endl;
    //FOR(i, 0, n) {
    //    FOR(j, 0, m) {
    //        cout << island[i][j] << ' ';
    //    }
    //    cout << endl;
    //}

    priority_queue<pllp, vector<pllp>, greater<pllp>> pq;

    FOR(i, 0, n) {
        vector<pii> num_cnt;
        int target = island[i][0];
        int target_cnt = 1;

        FOR(j, 1, m) {
            if (island[i][j] == target) {
                target_cnt++;
            }
            else {
                num_cnt.push_back({ target, target_cnt });
                target = island[i][j];
                target_cnt = 1;
            }
        }
        num_cnt.push_back({ target, target_cnt });
        FOR(idx, 0, num_cnt.size()) {
            // 0일 때 , 다리 길이가 2 이상이고, 좌우에 섬이 있을 때
            if (num_cnt[idx].first == 0 && num_cnt[idx].second >= 2) {
                if (idx != 0 && idx != num_cnt.size() - 1) {
                    pq.push({ num_cnt[idx].second , {num_cnt[idx - 1].first, num_cnt[idx + 1].first} });
                }
            }
        }
    }

    FOR(j, 0, m) {
        vector<pii> num_cnt;
        int target = island[0][j];
        int target_cnt = 1;

        FOR(i, 1, n) {
            if (island[i][j] == target) {
                target_cnt++;
            }
            else {
                num_cnt.push_back({ target, target_cnt });
                target = island[i][j];
                target_cnt = 1;
            }
        }
        num_cnt.push_back({ target, target_cnt });
        FOR(idx, 0, num_cnt.size()) {
            // 0일 때 , 다리 길이가 2 이상이고, 좌우에 섬이 있을 때
            if (num_cnt[idx].first == 0 && num_cnt[idx].second >= 2) {
                if (idx != 0 && idx != num_cnt.size() - 1) {
                    pq.push({ num_cnt[idx].second , {num_cnt[idx - 1].first, num_cnt[idx + 1].first} });
                }
            }
        }
    }

    vector<int> parent(island_cnt + 1);
    FOR(i, 0, island_cnt + 1) {
        parent[i] = i;
    }

    int ans = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        // cout << x << ' ' << y << ' ' << cost << endl;
        if (!Same(parent, x, y)) {
            ans += cost;
            Union(parent, x, y);
        }
    }

    bool flag = false;
    int check = parent[1];
    FOR(i, 1, island_cnt + 1) {
        if (!Same(parent, 1, i)) flag = true;
    }
    if (flag) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }

    
    


}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}