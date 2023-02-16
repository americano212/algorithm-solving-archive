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
	
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int m;
	cin >> m;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == m) {
			sum += 1;
		}
	}
	cout << sum << endl;
	return 0;
}