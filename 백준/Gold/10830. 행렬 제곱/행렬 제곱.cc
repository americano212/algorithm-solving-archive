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

matrix matrix_mul(matrix& A, matrix& B, int size) {
    matrix result(size, vector<ll>(size, 0));

    FOR(i, 0, size) {
        FOR(j, 0, size) {
            int sum = 0;
            FOR(k, 0, size) {
                sum += A[i][k] * B[k][j];
            }
            result[i][j] = sum % 1000;
        }
    }
    return result;
}

matrix recur(matrix& A, ll B, int size) {
    if (B == 1) return A;

    if (B % 2 == 1) {
        matrix tmp = recur(A, B - 1, size);
        return matrix_mul(tmp, A, size);
    }
    else {
        matrix tmp = recur(A, B / 2, size);
        return matrix_mul(tmp, tmp, size);
    }
}

void solve() {
    int N;
    ll B;

    cin >> N >> B;

    matrix A(N, vector<ll>(N, 0));

    FOR(i, 0, N) {
        FOR(j, 0, N) {
            cin >> A[i][j];
        }
    }

    matrix ans = recur(A, B, N);

    FOR(i, 0, N) {
        FOR(j, 0, N) {
            cout << ans[i][j] % 1000 << ' ';
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}