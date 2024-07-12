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


pair<char, char> node[26];

void caseA(char now) {
    if (now == '.') return;
    cout << now;
    caseA(node[now - 'A'].first);
    caseA(node[now - 'A'].second);
}

void caseB(char now) {
    if (now == '.') return;
    caseB(node[now - 'A'].first);
    cout << now;
    caseB(node[now - 'A'].second);
}

void caseC(char now) {
    if (now == '.') return;
    caseC(node[now - 'A'].first);
    caseC(node[now - 'A'].second);
    cout << now;
}


void solve() {
    int n;
    cin >> n;
    char a, b, c;
    FOR(i, 0, n) {
        cin >> a >> b >> c;
        node[a - 'A'].first = b;
        node[a - 'A'].second = c;
    }
    caseA('A');
    cout << endl;
    caseB('A');
    cout << endl;
    caseC('A');
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}