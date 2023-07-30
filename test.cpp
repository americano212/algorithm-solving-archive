#include <bits/stdc++.h>

#define endl '\n';
using namespace std;
typedef long long int ll;
typedef vector<vector<ll>> matrix;

const ll mod = 1000000007LL;

ll a, b, c, i, j, k, n, m, t;
ll test;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<ll> v(n + 1, 0);
    for (b = 0; b < m; b++)
    {
        cin >> i >> j >> k;
        for (int bkt = i; bkt < j + 1; bkt++)
        {
            v[bkt] = k;
        }
    }

    for (a = 1; a < n + 1; a++)
    {
        cout << v[a] << " ";
    }
    cout << endl;
}