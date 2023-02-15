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
	vector<ll> v(n+1);
	int tmp;
	for (int i = 1; i < n + 1; i++) {
		cin >> tmp;
		v[i] = v[i - 1] + tmp;
	}
	ll result = 0;
	for (int i = 0; i < n + 1; i++) {
		for (int j = i + 1; j < n + 1; j++) {
			result = max(result, min(v[j] - v[i], v[n] - (v[j] - v[i])));

;		}
	}
	cout << result << endl;
	return 0;
}