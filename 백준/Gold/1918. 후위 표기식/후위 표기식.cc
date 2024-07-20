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

string trans(vector<string>& s_part) {
    stack<string> left;
    stack<string> right;

    for (int i = s_part.size() - 1; i >= 0; i--) {
        right.push(s_part[i]);
    }
    // 곱, 나누기 처리
    while (!right.empty()) {
        string tmp;
        string target = right.top();
        right.pop();
        if (target == "*" || target == "/") {
            tmp += left.top();
            left.pop();
            tmp += right.top();
            right.pop();
            tmp += target;
            
            left.push(tmp);
        }
        else {
            left.push(target);
        }
    }
    // 오른쪽 스택에 리셋
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    // 플, 마 처리
    while (!right.empty()) {
        string tmp;
        string target = right.top();
        right.pop();
        if (target == "+" || target == "-") {
            tmp += left.top();
            left.pop();
            tmp += right.top();
            right.pop();
            tmp += target;
            left.push(tmp);
        }
        else {
            left.push(target);
        }
    }
    return left.top();
}

void solve() {
    string s;
    cin >> s;
    stack<string> st;

    for (int i = s.size() - 1; i >= 0; i--) {
        string str;
        str += s[i];

        // 괄호 처리
        if (str == "(") {
            vector<string> tmp_vec;
            while (1) {
                string tmp = st.top();
                st.pop();
                if (tmp == ")") break;
                tmp_vec.push_back(tmp);
            }
            st.push(trans(tmp_vec));
        }
        else {
            st.push(str);
        }
    }
    vector<string> vec_str;
    while (!st.empty()) {
        vec_str.push_back(st.top());
        st.pop();
    }
    cout << trans(vec_str) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}