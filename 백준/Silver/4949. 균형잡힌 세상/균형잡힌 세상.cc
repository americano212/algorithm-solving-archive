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
ll max_size = 0;


void solve() {
    string s;   
    while (1) {
        getline(cin, s);
        if (s == ".")break;
        stack<char> st;
        bool no_flag = false;

        FOR(i, 0, s.length()) {
            if (s[i] == '(' or s[i]=='[') {
                st.push(s[i]);
            }
            else if (s[i] == ']') {
                if (st.empty()) {
                    no_flag = true;
                    break;
                }
                if (st.top() != '[') {
                    no_flag = true;
                    break;
                }
                st.pop();
            }
            else if (s[i] == ')') {
                if (st.empty()) {
                    no_flag = true;
                    break;
                }
                if (st.top() != '(') {
                    no_flag = true;
                    break;
                }
                st.pop();
            }
        }
        if (no_flag || !st.empty()) {
            cout << "no" << endl;
        }
        else {
            cout << "yes" << endl;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}