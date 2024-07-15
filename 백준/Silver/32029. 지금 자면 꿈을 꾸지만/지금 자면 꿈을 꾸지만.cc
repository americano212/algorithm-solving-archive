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
int dy[4] = { 0,0,1,-1 };

using namespace std;


void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n);
    FOR(i, 0, n) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int ans = 0;

    // i번째 과제를 하기전 잠자기
    FOR(i, 0, n) {
        // x만큼 잠자기
        FOR(x, 0, a) {
            int total_time = 0;
            int complete_cnt = 0;
            // 탐색하면서 과제 완료 가능한지 확인
            FOR(j, 0, n) {
                if (i == j) total_time += b * x;
                // 지금 과제를 하기전 잔 경우 / 안 잔 경우
                int each_time = (i <= j) ? a - x : a;

                // 지금까지 걸린시간+과제하는 시간이 기한 안인가?
                if (v[j] >= total_time + each_time) {
                    complete_cnt++;
                    total_time += each_time;
                }
            }
            ans = max(ans, complete_cnt);
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