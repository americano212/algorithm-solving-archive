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


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int a, b;
	cin >> a >> b;

	vector<int> v(1001);
	int cnt = 1;
	for (int i = 1; i < 46; i++) {
		for (int j = 0; j < i; j++) {
			if (cnt == 1001) {
				break;
			}
			v[cnt] = i;
			cnt += 1;
		}
	}
	int sum = 0;
	for (int i = a; i < b+1; i++) {
		sum += v[i];
	}
	cout << sum << endl;
	return 0;
}