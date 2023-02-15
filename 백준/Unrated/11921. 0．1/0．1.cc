#include <iostream>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		cin >> m;
		ans += m;
	}
	cout << 10 << '\n';
	cout << ans;
	return 0;
}