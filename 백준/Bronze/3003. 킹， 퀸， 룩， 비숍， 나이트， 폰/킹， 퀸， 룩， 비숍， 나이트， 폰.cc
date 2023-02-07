#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int>v = {1,1,2,2,2,8};
    vector<int> chess(6);

    for (int i = 0; i < 6; i++)
    {
        cin >> chess[i];
        cout << v[i] - chess[i] << " ";
    }
    

	return 0;
}