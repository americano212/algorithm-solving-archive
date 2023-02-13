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

int L[101][101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			L[i][j] = 0;
		}
	}

	int n,a,b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		for (int j = a; j < a + 10; j++) {
			for (int k = b; k < b + 10; k++) {
				L[j][k] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (L[i][j] == 1) {
				ans += 1;
			}
		}
	}
	cout << ans;
	return 0;
}