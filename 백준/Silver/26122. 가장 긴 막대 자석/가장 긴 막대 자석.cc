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

	int k;
	cin >> k;
	string s;
	cin >> s;
	vector<int> v(k+1);

	int cnt = 1;
	int idx = 0;
	for (int i = 1; i < k+1; i++) {
		if (s[i] == s[i - 1]) {
			cnt += 1;
		}
		else {
			v[idx] = cnt;
			idx += 1;
			cnt = 1;
		}
		
	}
	int save = 0;
	for (int i = 1; i < k+1; i++) {

		save = max(save, min(v[i], v[i - 1]));
	}
	cout << save * 2 << endl;

	return 0;
}