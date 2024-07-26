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



void solve() {
    int n;
    cin >> n;
    
    deque<pair<char, ll>> qu;
    stack<pair<char, ll>> st;


    char c;
    int num;
    FOR(i, 0, n) {
        cin >> c >> num;
        qu.push_back({ c,num });
    }

    while (!qu.empty()) {
        // 몫은 qu 뒤로 넘기기, 단, qu.back과 합쳐야함
        // 나머지는 st으로 넣기, 단, st.top과 합쳐야함

        char target_c = qu.front().first;
        ll target_num = qu.front().second;
        qu.pop_front();

        if (!st.empty()) {
            if (st.top().first == target_c) {
                target_num += st.top().second;
                st.pop();
            }
        }

        ll quot = target_num / 3;
        ll remain = target_num % 3;
        
        if (!qu.empty()) {
            if (qu.back().first == target_c) {
                quot += qu.back().second;
                qu.pop_back();
            }
        }
        // cout << "!! " << target_c << ' ' << quot << ' ' << remain << endl;

        if(quot != 0) qu.push_back({ target_c, quot });
        
        if(remain != 0) st.push({ target_c, remain });

    }
    

    ll ans = 0;
    while (!st.empty()) {
        ans += st.top().second;
        st.pop();
    }
    
    cout << ans << endl;

    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    cin >> tc;
    while (tc--)solve();

    return 0;
}