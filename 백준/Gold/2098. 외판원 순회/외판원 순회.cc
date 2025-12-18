#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int N;
int dp[16][1 << 16];

int dfs(int now, int visit, const vector<vector<int>> &cost_graph){
    if(visit == (1 << N) - 1){
        if(cost_graph[now][0] == 0) return INF;
        return cost_graph[now][0];
    }

    if(dp[now][visit] != -1) return dp[now][visit];

    dp[now][visit] = INF;
    for(int next=0;next<N;next++){
        if(cost_graph[now][next] == 0) continue;

        if((visit & (1 << next)) == (1 << next)) continue;

        dp[now][visit] = min(dp[now][visit], cost_graph[now][next] + dfs(next, visit | (1 << next), cost_graph));
    }

    return dp[now][visit];
}

int travelling(int N, const vector<vector<int>> &cost_graph) {
    memset(dp, -1, sizeof(dp));
    return dfs(0, 1, cost_graph);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> N;

    vector<vector<int>> cost_graph(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost_graph[i][j];
        }
    }

    int ans = travelling(N, cost_graph);
    cout << ans << '\n';

    return 0;
}