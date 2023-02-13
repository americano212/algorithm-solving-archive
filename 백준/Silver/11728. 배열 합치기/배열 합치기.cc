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

	int n, m;
	cin >> n >> m;
	vector<int> v(n + m);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = n; i < n + m; i++) {
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());

	for (int i = 0; i < n + m; i++) {
		cout << v[i] << " ";
	}

	return 0;
}