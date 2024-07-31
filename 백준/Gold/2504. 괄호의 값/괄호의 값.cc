#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++) 
#define endl '\n';
#define INF 2'147'483'647
#define ll long long
#define ld long double
#define pii pair<int, int>
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

struct ITEM { bool isNum; int num = 0; char bracket = ' '; };

void solve() {
    string s;
    cin >> s;
    if (s.size() % 2 == 1) {
        cout << 0 << endl;
        return;
    }
    stack<ITEM> st;
    FOR(i, 0, s.size()) {
        if (s[i] == '(' || s[i] == '[') {
            st.push({ false,0,s[i] });
        }
        else if (s[i] == ')') {
            if (st.empty()) {
                cout << 0 << endl;
                return;
            }

            if (st.top().isNum) {
                int temp = st.top().num;
                st.pop();
                if (st.empty()) {
                    cout << 0 << endl;
                    return;
                }

                if (st.top().bracket == '(') {
                    st.pop();
                    st.push({ true,temp * 2,' ' });
                }
                else {
                    cout << 0 << endl;
                    return;
                }
            }
            else {
                if (st.top().bracket == '(') {
                    st.pop();
                    st.push({ true,2,' ' });
                }
                else {
                    cout << 0 << endl;
                    return;
                }
            }
        }
        else if (s[i] == ']') {
            if (st.empty()) {
                cout << 0 << endl;
                return;
            }

            if (st.top().isNum) {
                int temp = st.top().num;
                st.pop();
                if (st.empty()) {
                    cout << 0 << endl;
                    return;
                }

                if (st.top().bracket == '[') {
                    st.pop();
                    st.push({ true,temp * 3,' ' });
                }
                else {
                    cout << 0 << endl;
                    return;
                }
            }
            else {
                if (st.top().bracket == '[') {
                    st.pop();
                    st.push({ true,3,' ' });
                }
                else {
                    cout << 0 << endl;
                    return;
                }
            }
        }
        int temp = 0;
        while (1) {
            if (st.empty()) {
                if (temp != 0) st.push({ true,temp,' ' });
                break;
            }

            if (st.top().isNum) {
                temp += st.top().num;
                st.pop();
            }
            else {
                if (temp != 0) {
                    st.push({ true,temp,' ' });
                }
                break;
            }
        }
        //if (st.top().isNum) {
        //    cout << st.top().num << ' ';
        //}
        //else {
        //    cout << st.top().bracket << ' ';
        //}
    }
    // cout << endl;
    if (st.size() != 1) {
        cout << 0 << endl;
    }
    else {
        cout << st.top().num << endl;
    }
    
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}