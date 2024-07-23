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
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;

    deque<char> dq;

    stack<int> st;

    char s2_end = s2[s2.size() - 1];

    FOR(idx, 0, s1.size()) {
        dq.push_back(s1[idx]);
        //cout << "!! " << dq.size() << endl;
        bool flag = true;
        if (dq.back() == s2_end && dq.size()>= s2.size()) {
            // cout << "????????" << endl;
            FOR(i, 0, s2.size()) {
                //cout << "?? " << dq[dq.size() - i - 1] << ' ' << s2[s2.size() - i - 1] << endl;
                if (dq[dq.size() - i - 1] != s2[s2.size() - i - 1]) flag = false;
            }
            
            if (flag) {
                FOR(i, 0, s2.size()) dq.pop_back();
            }
        }

        
    }
    if (dq.size() != 0) {
        FOR(i, 0, dq.size()) {
            cout << dq[i];
        }
    }
    else {
        cout << "FRULA";
    }
    cout << endl;

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}