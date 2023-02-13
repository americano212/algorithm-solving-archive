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

	ll a, l;
	cin >> a >> l;
	if (a == 1) {
		cout << a * l;
	}
	else {
		cout << a * (l - 1) + 1;
	}
	return 0;
}