#include <bits/stdc++.h>
#define btw(n, x, y) x <= n &&n < y
#define pii pair<int, int>
using namespace std;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        // cout << v[i] << ' ';
        if (n - i >= v[i]) {
            ans = max(ans, v[i]);
        } else {
            ans = max(ans, n - i);
        }
    }
    // cout << endl;
    cout << ans << endl;
}
