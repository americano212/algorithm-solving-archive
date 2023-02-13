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

	string s;
	cin >> s;
	int ans = 1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != s[i - 1]) {
			ans += 1;
		}
	}
	cout << ans / 2 << endl;
	return 0;
}