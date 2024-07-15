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
int dy[4] = { 0,0,1,-1};
using namespace std;

int r, c;

void bfs(vector<vector<vector<bool>>>& visit, vector<string>& mat, int x, int y, int z) {
    
    queue<vector<int>> qu;
    qu.push({ x,y,z });

    while (!qu.empty()) {
        int now_x = qu.front()[0];
        int now_y = qu.front()[1];
        int now_z = qu.front()[2];
        qu.pop();

        if (mat[now_x / 2][now_y / 2] == 'O' && visit[now_x][now_y][1 - now_z] == false) {
            qu.push({ now_x,now_y,1 - now_z });
            visit[now_x][now_y][1 - now_z] = true;
        }

        FOR(idx, 0, 4) {
            int next_x = now_x + dx[idx];
            int next_y = now_y + dy[idx];
            if (0 <= next_x && next_x < 2 * r && 0 <= next_y && next_y < 2 * c ) {
                // 같은 원기둥일 때
                if (now_x / 2 == next_x / 2 && now_y / 2 == next_y / 2) {
                    if (mat[next_x / 2][next_y / 2] == 'I' && visit[next_x][next_y][now_z] == false && dy[idx] == 0) {
                        qu.push({ next_x,next_y,now_z });
                        visit[next_x][next_y][now_z] = true;
                    }
                    if (mat[next_x / 2][next_y / 2] == 'H' && visit[next_x][next_y][now_z] == false && dx[idx] == 0) {
                        qu.push({ next_x,next_y,now_z });
                        visit[next_x][next_y][now_z] = true;
                    }
                }
                else {
                    //cout << "?? " << next_x << ' ' << next_y << ' ' << now_z << ' ' << endl;
                    //cout << "??? " << now_x << ' '<< now_y << endl;
                    if (visit[next_x][next_y][now_z] == false) {
                        qu.push({ next_x,next_y,now_z });
                        visit[next_x][next_y][now_z] = true;
                    }
                }
            }
        }
    }
}

void solve() {
    
    cin >> r >> c;
    vector<string> mat(r);

    FOR(i, 0, r) {
        cin >> mat[i];
    }

    vector<vector<vector<bool>>> visit(2 * r, vector<vector<bool>>(2 * c, vector<bool>(2, false)));

    int ans = 0;

    FOR(i, 0, 2 * r) {
        FOR(j, 0, 2 * c) {
            FOR(k, 0, 2) {
                if (visit[i][j][k] == false) {
                    visit[i][j][k] = true;
                    // cout << "tt " << i << ' ' << j << ' ' << k << endl;
                    bfs(visit, mat, i, j, k);
                    ans++;
                }
            }
        }
    } 
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}