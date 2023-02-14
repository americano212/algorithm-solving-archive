#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <climits>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cstring>
#include <cassert>
using ll = long long;
using namespace std;
ll inf = 1000000007;

ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<ll> v(n + 1);
		ll sum = 0;
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		for (int j = 0; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				sum += gcd(v[j], v[k]);
			}
		}
		cout << sum << endl;
	}

	return 0;
}