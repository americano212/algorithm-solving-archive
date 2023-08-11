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
    string s, target;
    getline(cin, s);
    getline(cin, target);
    if (s.length() < target.length())
    {
        cout << 0 << endl;
        return 0;
    }
    int count = 0;
    for (i = 0; i <= s.length() - target.length(); i++)
    {
        if (s[i] == target[0])
        {
            string sub = s.substr(i, target.length());
            if (sub == target)
            {
                count += 1;
                i += target.length() - 1;
            }
        }
    };
    cout << count << endl;
}