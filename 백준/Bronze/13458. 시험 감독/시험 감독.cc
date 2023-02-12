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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, b, c;
	cin >> n;
	ll ans = 0, tmp;
	vector<int> v(1000001);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		if (v[i] <= b) {
			ans += 1;
		}
		else if ((v[i] - b) % c) {
			ans += (v[i] - b) / c + 2;
		}
		else {
			ans += (v[i] - b) / c + 1;
		}
	}
	cout << ans;
	return 0;
}