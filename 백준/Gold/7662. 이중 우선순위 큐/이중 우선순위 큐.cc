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
    int k;
    cin >> k;
    priority_queue<int, vector<int>> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    map<int, int> map;

    int cnt = 0;
    char c;
    int n;
    FOR(i, 0, k) {
        cin >> c >> n;
        if (c == 'I') {
            max_pq.push(n);
            min_pq.push(n);
            cnt++;
            if (map.find(n) != map.end()) {
                map[n] += 1;
            }
            else {
                map[n] = 1;
            }
        }
        else {
            if (cnt == 0) continue;

            if (n == -1) {
                while (1) {
                    if (map[min_pq.top()] > 0) {
                        map[min_pq.top()] -= 1;
                        min_pq.pop();
                        break;
                    }
                    else {
                        min_pq.pop();
                    }
                }
                cnt--;
            }
            else {
                while (1) {
                    if (map[max_pq.top()] > 0) {
                        map[max_pq.top()] -= 1;
                        max_pq.pop();
                        break;
                    }
                    else {
                        max_pq.pop();
                    }
                }
                cnt--;
            }
        }
    }
    if (cnt == 0) {
        cout << "EMPTY" << endl;
    }
    else {
        while (1) {
            if (map[max_pq.top()] > 0) {
                cout << max_pq.top() << ' ';
                break;
            }
            else {
                max_pq.pop();
            }
        }
        while (1) {
            if (map[min_pq.top()] > 0) {
                cout << min_pq.top() << endl;
                break;
            }
            else {
                min_pq.pop();
            }
        }
        // cout << max_pq.top() << ' ' << min_pq.top() << endl;
    }
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    cin >> tc;
    while (tc--)solve();

    return 0;
}