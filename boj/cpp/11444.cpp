#include <bits/stdc++.h>

#define endl '\n';
using namespace std;
typedef long long int ll;
typedef vector<vector<ll>> matrix;

const ll mod = 1000000007LL;

ll a, b, c, i, j, k, n, m, t;
ll test;

matrix matrix22_mul(matrix &a, matrix &b)
{
    matrix result(2, vector<ll>(2));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
            result[i][j] %= mod;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    matrix ans = {{1, 0}, {0, 1}};
    matrix fibo = {{1, 1}, {1, 0}};

    if (n <= 1)
    {
        cout << n << endl;
        return 0;
    }
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans = matrix22_mul(ans, fibo);
        }
        fibo = matrix22_mul(fibo, fibo);
        n /= 2;
    }
    cout << ans[0][1] << endl;
}