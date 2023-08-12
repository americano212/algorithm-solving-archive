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
    int h;
    cin >> n >> h;
    vector<int> v(n);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (i = 0; i < n; i++)
    {
        if (v[i] <= h)
        {
            h += 1;
        }
        else
        {
            break;
        }
    }
    cout << h << endl;
}