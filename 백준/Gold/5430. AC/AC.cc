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


void solve() {
    string order;
    cin >> order;
    int n;
    cin >> n;
    string target;
    cin >> target;

    vector<int> v;

    string tmp = "";
    FOR(i, 0, target.length()) {
        if (isdigit(target[i])) {
            tmp += target[i];
        }
        else {
            if (!tmp.empty()) {
                v.push_back(stoi(tmp));
                tmp = "";
            }
        }
    }
    //FOR(i, 0, n) {
    //    cout << v[i] << ' ';
    //}
    //cout << endl;
    bool isReverse = false;
    int left_point = 0;
    int right_point = n - 1;
    FOR(i, 0, order.size()) {
        if (order[i] == 'R') {
            isReverse = !isReverse;
        }
        if (order[i] == 'D') {
            if (!isReverse) {
                left_point++;
            }
            else {
                right_point--;
            }
        }
        if (left_point - 1 > right_point) {
            cout << "error" << endl;
            return;
        }
    }

    cout << '[';
    if (!isReverse) {
        FOR(i, left_point, right_point + 1) {
            cout << v[i];
            if (i != right_point) cout << ',';
        }
    }
    else {
        for (int i = right_point; i >= left_point; i--) {
            cout << v[i];
            if (i != left_point) cout << ',';
        }
    }
    cout << ']' << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    cin >> tc;
    while (tc--)solve();

    return 0;
}