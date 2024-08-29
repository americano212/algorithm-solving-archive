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
#define pdd pair<double, double>
#define pldd pair<ld, ld>
#define matrix vector<vector<ll>>
#define lcm(a, b) a * b / gcd(a, b)
#define all(v) v.begin(), v.end()
#define btw(x,a,b) a<=x && x<b
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

const ll mod = 1'000'000'000LL;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int dx6[6] = { 1,-1,0,0,0,0 };
int dy6[6] = { 0,0,1,-1,0,0 };
int dz6[6] = { 0,0,0,0,1,-1 };
int dx8[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy8[8] = { 1,1,0,-1,-1,-1,0,1 };

using namespace std;

struct EDGE { ll start; ll end; ll cost; };
struct DOT3 { ll x; ll y; ll z; };
struct NODE { int x; int y; int dir; };
struct ITEM { bool isNum; int num = 0; char bracket = ' '; };

vector<int> parent(51, 0);

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    int a = Find(x);
    int b = Find(y);
    if (a < b) parent[a] = b;
    else parent[b] = a;
}

bool Same(int x, int y) {
    int a = Find(x);
    int b = Find(y);
    return a == b;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int truth_cnt;
    cin >> truth_cnt;

    FOR(i, 0, 51) {
        parent[i] = i;
    }

    vector<int> truth_member_list(truth_cnt);
    FOR(i, 0, truth_cnt) {
        cin >> truth_member_list[i];
    }

    vector<int> party_leader_list;

    FOR(_, 0, m) {
        int party_mem_cnt;
        cin >> party_mem_cnt;
        int party_leader = 0;
        int member;
        FOR(i, 0, party_mem_cnt) {
            cin >> member;
            if (i == 0) {
                party_leader = member;
                party_leader_list.push_back(member);
                continue;
            }

            Union(party_leader, member);
        }
    }


    int ans = 0;

    FOR(i, 0, party_leader_list.size()) {
        int party_leader = party_leader_list[i];
        bool check = true;
        FOR(j, 0, truth_cnt) {
            int truth_member = truth_member_list[j];
            if (Same(party_leader, truth_member)) check = false;
        }

        if (check) ans++;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--)solve();

    return 0;
}