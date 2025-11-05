#include <bits/stdc++.h>
#define btw(n, x, y) x <= n &&n < y
#define pii pair<int, int>
using namespace std;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> mat(n, vector<vector<int>>(m, vector<int>(3, 0)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a, b, c;
            cin >> a >> b >> c;
            mat[i][j] = {a, b, c};
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pii> qu;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == false) {
                ans++;
                qu.push({i, j});
                visited[i][j] = true;
                while (!qu.empty()) {
                    auto [x, y] = qu.front();
                    qu.pop();
                    for (int idx = 0; idx < 8; idx++) {
                        int nx = x + dx[idx];
                        int ny = y + dy[idx];
                        if (btw(nx, 0, n) && btw(ny, 0, m) && visited[nx][ny] == false) {
                            if (mat[nx][ny] == mat[x][y]) {
                                // cout << nx << ' ' << ny << endl;
                                visited[nx][ny] = true;
                                qu.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
