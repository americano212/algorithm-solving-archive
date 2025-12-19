#include <bits/stdc++.h>

using namespace std;

struct dot {
    int a;
    int b;
    int c;
};

#define pii pair<int,int>
#define btw(n,x,y) x<=n && n<y
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,-1,1,-1,1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> row_prefix(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> col_prefix(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            row_prefix[i][j] = row_prefix[i][j - 1] + matrix[i][j];
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            col_prefix[i][j] = col_prefix[i - 1][j] + matrix[i][j];
        }
    }

    //for (int i = 1; i <= n; i++) {
    //    for (int j = 1; j <= m; j++) {
    //        cout << row_prefix[i][j] << ' ';
    //    }
    //    cout << endl;
    //}


    for (int i = k/2 + 1; i <= n; i+=s) {
        for (int j = k/2 + 1; j <= m; j+=s) {
            int ans = 0;
            if (j + k / 2 > m || i + k / 2 > n) continue;
            ans += row_prefix[i][j + k / 2] - row_prefix[i][j - k / 2 - 1];
            ans += col_prefix[i + k / 2][j] - col_prefix[i - k / 2 - 1][j];
            ans -= matrix[i][j];
            cout << ans << ' ';
        }
        cout << endl;
    }
}