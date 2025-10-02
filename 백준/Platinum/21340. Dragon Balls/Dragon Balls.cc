#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

long long ask(long long y, long long x) {
    cout << y << ' ' << x << endl;
    long long ret;
    cin >> ret;
    return ret;
}

ll w = 1000001LL;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    // write your code here

    int found_ball = 0;

    ll idx_k = 0;
    while (true) {
        if (found_ball == N)
            break;

        int remaining_ball = N - found_ball;
        vector<pll> v(remaining_ball + 1); // {k, d^2}

        bool flag = false;
        for (int i = 0; i < remaining_ball + 1; i++) {

            ll query = ask(0, idx_k);
            v[i] = {idx_k, query};
            idx_k++;
            if (query == 0) {
                found_ball++;
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        for (int i = 0; i < remaining_ball + 1; i++) {
            for (int j = i + 1; j < remaining_ball + 1; j++) {
                ll d1 = v[i].second;
                ll d2 = v[j].second;
                ll k1 = v[i].first;
                ll k2 = v[j].first;

                ll expectation_x = (d1 - d2 - k1 * k1 + k2 * k2) / (2 * (k2 - k1));

                ll expectation_y = (ll) sqrt(d1 - (expectation_x - k1) * (expectation_x - k1));
                if (0 <= expectation_x && expectation_x < w && 0 <= expectation_y && expectation_y < w) {
                    if (ask(expectation_y, expectation_x) == 0) {
                        found_ball++;
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)
                break;
        }
    }

    return 0;
}
