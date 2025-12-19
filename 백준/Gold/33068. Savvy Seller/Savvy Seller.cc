#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define pllp pair<ll, pll>
#define btw(n,x,y) x<=n && n<y
#define all(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    ll s, e, p;
    vector<pllp> meetings(n+1);

    for (int i = 1; i < n + 1; i++) {
        cin >> s >> e >> p;
        meetings[i] = { e,{s,p} };
    }

    sort(all(meetings));
    vector<int> end_times;
    for (int i = 1; i < n + 1; i++) {
        end_times.push_back(meetings[i].first);
        //cout << meetings[i].first << ' ';
    }
    // cout << endl;

    vector<ll> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int now_start = meetings[i].second.first;
        ll now_profit = meetings[i].second.second;

        int idx = upper_bound(end_times.begin(), end_times.begin() + i - 1, now_start) - end_times.begin();

        dp[i] = max(dp[i - 1], now_profit + dp[idx]);
    }
    cout << dp[n] << endl;
}