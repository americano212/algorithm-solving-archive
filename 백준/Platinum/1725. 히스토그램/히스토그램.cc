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

ll recur(vector<ll> &v, int left, int right){
    if (left == right) return v[left];

    int mid = (left + right) / 2;

    
    ll maximum = 0;

    maximum = max(maximum, recur(v, left, mid));
    maximum = max(maximum, recur(v, mid + 1, right));

    ll height = min(v[mid], v[mid + 1]);
    int left_pivot = mid;
    int right_pivot = mid + 1;

    max_size = max(max_size, height * 2);
    max_size = max(max_size, v[mid]);
    max_size = max(max_size, v[mid + 1]);
    // cout << left << " " << mid << " " << right << " " << max_size << endl;


    while (left <= left_pivot && right_pivot <= right) {
        //cout << left << " " << left_pivot << " " << right << " " << right_pivot << endl;
        if (right_pivot == right && left < left_pivot) {
            height = min(height, v[left_pivot - 1]);
            left_pivot--;
        }
        else if (left_pivot == left && right_pivot < right) {
            height = min(height, v[right_pivot + 1]);
            right_pivot++;
        }
        else if (left_pivot == left && right_pivot == right) {
            break;
        }
        else if (v[left_pivot - 1] > v[right_pivot + 1]) {
            height = min(height, v[left_pivot - 1]);
            left_pivot--;
        }
        else if (v[left_pivot - 1] <= v[right_pivot + 1]) {
            height = min(height, v[right_pivot + 1]);
            right_pivot++;
        }
        max_size = max(max_size, height * (right_pivot - left_pivot + 1));
    }
    return max_size;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    FOR(i, 0, n) {
        cin >> v[i];
    }
    cout << recur(v, 0, n-1) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}