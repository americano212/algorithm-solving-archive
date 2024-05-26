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
int a = 0;
int b = 0;
int c = 0;

void paper(matrix &mat, int x1, int y1, int size) {

    bool a_check = (mat[x1][y1] == -1);
    bool b_check = (mat[x1][y1] == 0);
    bool c_check = (mat[x1][y1] == 1);

    FOR(i, x1, x1+ size) {
        FOR(j, y1, y1+ size) {
            if (a_check) {
                if (mat[i][j] == 0 || mat[i][j] == 1) a_check = false;
            }
            if (b_check) {
                if (mat[i][j] == -1 || mat[i][j] == 1) b_check = false;
            }
            if (c_check) {
                if (mat[i][j] == -1 || mat[i][j] == 0) c_check = false;
            }
        }
    }
    if (a_check) {
        a++;
        return;
    }
    if (b_check) {
        b++;
        return;
    }
    if (c_check) {
        c++;
        return;
    }
    

    int next = size / 3;

    FOR(i,0,3){
        FOR(j, 0, 3) {
            paper(mat, x1 + next * i, y1 + next * j, next);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    matrix mat(n, vector<ll>(n, 0));

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cin >> mat[i][j];
        }
    }

    paper(mat, 0, 0, n);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}