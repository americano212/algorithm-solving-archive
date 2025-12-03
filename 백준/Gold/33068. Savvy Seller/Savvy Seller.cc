#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;

vector<pair<int, int>> salesman(int N, vector<pair<int, int>> meetings) {
    vector<pii> answer;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < N; i++) {
        pq.push({meetings[i].second, meetings[i].first});
    }

    int last_end = 0;
    while (!pq.empty()) {
        auto [b, a] = pq.top();
        pq.pop();
        if (last_end <= a) {
            last_end = b;
            answer.push_back({a, b});
        }
    }
    // TODO: Implement the salesman function

    return answer;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> meetings(N);
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> meetings[i].first >> meetings[i].second >> tmp;
    }

    vector<pair<int, int>> ans = salesman(N, meetings);

    // for (auto meeting: ans) {
    //     cout << meeting.first << " " << meeting.second << " ";
    // }
    // cout << '\n';
    cout << ans.size() << endl;

    return 0;
}
