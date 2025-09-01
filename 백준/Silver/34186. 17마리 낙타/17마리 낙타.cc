#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

#define INF 0x3FFFFFFF

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll, ll>;

ll gcd(ll a, ll b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a * b / g;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        ll n, a, b, c;
        cin >> n >> a >>  b >> c;
        ll l = lcm(a, b);
        l = lcm(l, c);
        //cout << l << endl;
        ll k = l / a + l / b + l / c;
        //cout << k << endl;
        if(n % k != 0) {
            cout << "-1\n";
            continue;
        }
        if(l - k < 0){
            cout << "-1\n";
            continue;
        }

        cout << (l-k) * (n / k) << "\n";
    }

    return 0;
}