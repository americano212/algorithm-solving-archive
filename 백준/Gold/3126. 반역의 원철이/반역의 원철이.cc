#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pllp pair<ll, pll>
#define pff pair<float, float>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
#define all(v) v.begin(), v.end()
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'007LL;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

double dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
double dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

char s[100001];

void solve() {
    double mx, my, bx, by;
    cin >> mx >> my >> bx >> by;

    int n;
    cin >> n;
    
    vector<int> direction(n);
    cin >> s;
    FOR(i, 0, n) {
        direction[i] = s[i] - '0';
    }

    vector<ll> sum_direction(n);

    sum_direction[0] = direction[0];
    FOR(i, 1, n) {
        sum_direction[i] = direction[i] + sum_direction[i - 1];
    }
    //FOR(i, 0, n) {
    //    cout << sum_direction[i] << ' ';
    //}
    //cout << endl;

    matrix mat(n + 1, vector<ll>(8, 0));


    FOR(i, 1, n + 1) {
        FOR(j, 0, 8) {
            mat[i][j] = mat[i - 1][j];
        }
        mat[i][sum_direction[i - 1] % 8]++;
    }

    //FOR(i, 0, n + 1) {
    //    FOR(j, 0, 8) {
    //        cout << mat[i][j] << ' ';
    //    }
    //    cout << endl;
    //}

    // 답
    double min_ans = INF;

    // 꺾이는 지점 설정
    FOR(i, 0, n) {
        // 몇 만큼 밀지
        FOR(k, 0, 8) {
            double x = mx;
            double y = my;
            // 각 경우 확인
            FOR(j, 0, 8) {
                x += mat[i][j] * dx8[j];
                y += mat[i][j] * dy8[j];

                x += (mat[n][j] - mat[i][j]) * dx8[(j + k) % 8];
                y += (mat[n][j] - mat[i][j]) * dy8[(j + k) % 8];
            }
            // cout << i << ' ' << k << ' ' << x << ' ' << y << endl;
            min_ans = min(min_ans, sqrt((bx - x) * (bx - x) + (by - y) * (by - y)));
        }
    }
    cout.precision(20);
    cout << min_ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}