#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;

ll factorial[17];

void solve() {
    int N;
    cin >> N;

    vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];

    // dp[i][mask] : i번째 위치까지 결정했을 때, 사용한 숫자의 비트마스크가 mask인 경우의 수
    // mask의 비트 j가 1이면 숫자 j+1을 이미 사용했음을 의미함
    vector<vector<ll>> dp(N + 1, vector<ll>(1 << N, 0));
    
    dp[0][0] = 1;

    for (int i = 0; i < N; ++i) {
        int val1 = a[i] - 1; // 0-indexed
        int val2 = b[i] - 1;

        for (int mask = 0; mask < (1 << N); ++mask) {
            if (dp[i][mask] == 0) continue;

            // 1. i번째 위치에서 아무런 위반도 하지 않는 경우 (나중에 (N-k)!을 곱함)
            dp[i + 1][mask] += dp[i][mask];

            // 2. i번째 위치에서 a[i]를 선택하여 위반하는 경우
            if (!(mask & (1 << val1))) {
                dp[i + 1][mask | (1 << val1)] += dp[i][mask];
            }

            // 3. i번째 위치에서 b[i]를 선택하여 위반하는 경우 (a[i] != b[i] 일 때만 별도 계산)
            if (val1 != val2 && !(mask & (1 << val2))) {
                dp[i + 1][mask | (1 << val2)] += dp[i][mask];
            }
        }
    }

    ll ans = 0;
    for (int mask = 0; mask < (1 << N); ++mask) {
        int k = 0;
        for (int i = 0; i < N; i++) if (mask & (1 << i)) k++;

        // 포함 배제 원리: k개의 원소를 고정(위반)시켰을 때 나머지 (N-k)! 배치
        // k가 짝수면 더하고, 홀수면 뺀다
        if (k % 2 == 1) {
            ans -= dp[N][mask] * factorial[N - k];
        } else {
            ans += dp[N][mask] * factorial[N - k];
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    factorial[0] = 1;
    for (int i = 1; i <= 16; i++) factorial[i] = factorial[i - 1] * i;

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}