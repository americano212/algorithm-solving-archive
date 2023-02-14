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

	int n, k;
	cin >> n >> k;
	vector<int> v(n + 1);
	for (int i = 0; i < n + 1; i++) {
		v[i] = 0;
	}
	int flag = 0 , target;
	while (true) {
		target = 0;
		for (int i = 2; i < n + 1; i++) {
			if (v[i] == 0 && target == 0) {
				target = i;
				v[i] = 1;
				k -= 1;
			}
			else if (v[i] == 0 && target != 0) {
				if (i%target == 0) {
					k -= 1;
					v[i] = 1;
				}
			}
			else {
				continue;
			}
			if (k == 0) {
				flag = i;
				break;
			}
		}
		if (flag != 0) {
			cout << flag << endl;
			break;
		}
	}

	return 0;
}