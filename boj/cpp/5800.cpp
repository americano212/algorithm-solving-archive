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
    cin >> t;
    for (i = 0; i < t; i++)
    {
        cin >> n;
        vector<int> v(n, 0);
        for (j = 0; j < n; j++)
        {
            cin >> v[j];
        }
        sort(v.begin(), v.end());
        cout << "Class " << i + 1 << endl;
        int gap = 0;
        for (j = 1; j < n; j++)
        {
            gap = max(gap, v[j] - v[j - 1]);
        }
        cout << "Max ";
        cout << v[n - 1] << ", Min " << v[0] << ", Largest gap " << gap << endl;
    }
}