#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int>v = {31,28,31,30,31,30,31,31,30,31,30,31};
    int month, day;
    cin >> month >> day;

    int cnt=0;
    for (int i = 0; i < month-1; i++)
    {
        cnt+= v[i];
    }
    cnt += day - 1;

    vector<string>week = {"MON", "TUE", "WED", "THU", "FRI", "SAT","SUN"};
    cout << week[cnt%7];

	return 0;
}