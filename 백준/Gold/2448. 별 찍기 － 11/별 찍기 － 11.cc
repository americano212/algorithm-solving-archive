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


void erase(int start_x, int start_y, int size, vector<vector<char>>& mat) {
    /*cout << start_x << ' ' << start_y << ' ' << size << endl;*/
    // left
    FOR(i, start_x, size + start_x) {
        FOR(j, start_y, size - (i - start_x) - 1 + start_y) {
            mat[i][j] = ' ';
        }
    }
    
    // right
    FOR(i, start_x, size + start_x) {
        FOR(j, size + (i - start_x) + start_y, 2 * size + start_y) {
            mat[i][j] = ' ';
        }
    }
    
    // center
    if (size == 3) {
        mat[start_x + 1][start_y + 2] = ' ';
    }
    //else {
    //    FOR(i, size / 2 + start_x, size + start_x) {
    //        FOR(j, i + start_y, i + (size - i) * 2 - 1 + start_y) {
    //            mat[i][j] = ' ';
    //        }
    //    }
    //}
    if (size == 3) return;
    int delta[3][2] = { {0, size / 2},{size / 2,0},{size / 2,size} };
    FOR(i, 0, 3) {
        erase(start_x + delta[i][0], start_y + delta[i][1], size / 2, mat);
        
    }
}

void solve() {
    int n;
    cin >> n;
    
    vector<vector<char>> mat(n, vector<char>(2 * n, '*'));
    erase(0, 0, n, mat);
    FOR(i, 0, n) {
        FOR(j, 0, 2 * n) {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}