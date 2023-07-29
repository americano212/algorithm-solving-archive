#include <bits/stdc++.h>

#define endl '\n';
using namespace std;
typedef long long int ll;

ll a, b, c, i, j, k, n, m, t;
ll test;

int p = 15 * pow(10, 5);
int mod = pow(10, 6);
int fibo[15 * 100000] = {0, 1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (i = 2; i < p; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fibo[i] %= mod;
    }
    cout << fibo[n % p] << endl;
}