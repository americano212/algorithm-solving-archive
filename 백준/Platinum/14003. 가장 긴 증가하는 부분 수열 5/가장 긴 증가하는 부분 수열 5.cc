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

ll binary_search(vector<ll>& v, int left, int right, int target) {
    int mid = (left + right) / 2;
    if (left == right) return mid;
    if (target < v[left]) return left;
    if (target > v[right]) return right;

    if (v[mid] < target) {
        return binary_search(v, mid + 1, right, target);
    }
    else {
        return binary_search(v, left, mid, target);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n, 0);
    vector<int> tracking(n, -1);

    FOR(i, 0, n) {
        cin >> v[i];
    }

    vector<ll> cache;
    cache.push_back(-1000000001);

    int max_index = -1;

    FOR(i, 0, n) {
        ll position = binary_search(cache, 0, cache.size() - 1, v[i]);
        /*cout << position << endl;*/


        if (position + 1 == cache.size() && cache[position] < v[i]) {
            cache.push_back(v[i]);
            tracking[i] = position + 1;
        }
        else {
            if (cache[position] > v[i]) {
                cache[position] = v[i];
                tracking[i] = position;
            }
        }
        
        
    }
    cout << cache.size() - 1 << endl;


    //FOR(i, 0, n) {
    //    cout << tracking[i] << ' ';
    //}
    int cnt = cache.size() - 1;
    stack<ll> answer;
    for (int i = tracking.size()-1; i >= 0; i--) {
        if (tracking[i] == cnt) {
            answer.push(v[i]);
            cnt--;
        }
    }

    while (!answer.empty()) {
        cout << answer.top() << ' ';
        answer.pop();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}