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
int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

struct EDGE {
    ll start;
    ll end;
    ll cost;
};

//struct CMP {
//    bool operator() (INFO a, INFO b) {
//        return a.cost > b.cost;
//    }
//};

// 피보나치 수 저장
map<ll, ll> m;

ll fibo(ll n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    ll a, b, result;
    if (n % 2 == 1) {
        a = (m.find(n / 2) != m.end()) ? m[n / 2] : fibo(n / 2);
        b = (m.find(n / 2 + 1) != m.end()) ? m[n / 2 + 1] : fibo(n / 2 + 1);
        
        a %= mod;
        b %= mod;
        result = (a * a % mod + b * b % mod) % mod;

        m.insert({ n / 2, a });
        m.insert({ n / 2 + 1, b });
        m.insert({ n, result });

        return result;
    }
    else {
        a = (m.find(n / 2) != m.end()) ? m[n / 2] : fibo(n / 2);
        b = (m.find(n / 2 - 1) != m.end()) ? m[n / 2 - 1] : fibo(n / 2 - 1);
        
        a %= mod;
        b %= mod;
        result = (a * (2 * b + a) % mod) % mod;

        m.insert({ n / 2, a });
        m.insert({ n / 2 - 1, b });
        m.insert({ n, result }); 
        return result;
    }
}

void solve() {
    ll n;
    cin >> n;
    cout << fibo(n) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}