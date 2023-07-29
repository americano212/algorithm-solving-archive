#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int test;
    cin >> test;

    int fst = 1, scd = 1, temp;

    for (int i = 0; i < test; i++)
    {
        ll n, m;

        cin >> n >> m;
        fst = 1, scd = 1;
        ll period;
        for (period = 2; period < m * m - 1; period++)
        {
            temp = fst;
            fst = scd;
            scd += temp;
            fst %= m;
            scd %= m;
            if (fst == 0 && scd == 1)
                break;
        }
        cout << n << " " << period << '\n';
    }
}