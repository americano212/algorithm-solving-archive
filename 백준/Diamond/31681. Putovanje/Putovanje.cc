#include <bits/stdc++.h>
#define FOR(x,y,n)  for(int x=y;x<(n);x++)
#define endl '\n'
using namespace std;

bitset<50001> check[50001];

void solve() {
    int n, m;
    cin >> n >> m;
    int a, b;
    vector<vector<int>> mat(n + 1);
    FOR(i, 0, m) {
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    vector<int> di(n + 1);

    int max_di = 0;
    FOR(i, 1, n + 1) {
        cin >> di[i];
        max_di = max(max_di, di[i]);
    }

    int red_cnt = 0;

    vector<vector<int>> di_level(max_di + 1);
    FOR(i, 1, n + 1) {
        if (di[i] != -1) {
            di_level[di[i]].push_back(i);
            red_cnt++;
        }
    }

    // di 큰거 부터 묶어서 queue에 넣고 bfs 돌리기
    queue<int> qu;
    vector<int> visited_di(n + 1, -1); // 방문한 시점의 di 기록


    for (int i = max_di; i > 0; i--) { // i = 현재 di 값 
        FOR(j, 0, di_level[i].size()) {
            int node = di_level[i][j];
            // 방문한 적 없는 경우
            if (visited_di[node] == -1) {
                visited_di[node] = i;
                qu.push(node);
                check[node].set(node, 1); // bit map에 마킹
            }
            // 방문은 했지만 동일한 di 값으로 방문한 경우
            if (visited_di[node] == i) {
                check[node].set(node, 1);
            }
        }
        int q_size = qu.size();
        while (q_size--) {
            int now = qu.front();
            qu.pop();
            FOR(idx, 0, mat[now].size()) {
                int next = mat[now][idx];
                if (visited_di[next] == -1) {
                    visited_di[next] = i - 1;
                    qu.push(next);
                    check[next] = check[now] | check[next];
                }
                if (visited_di[next] == i - 1) {
                    check[next] = check[now] | check[next];
                }
            }
        }
    }

    FOR(i, 0, di_level[0].size()) {
        int node = di_level[0][i];
        if (visited_di[node] == -1) {
            visited_di[node] = 0;
            qu.push(node);
            check[node].set(node, 1);
        }
        if (visited_di[node] == 0) {
            check[node].set(node, 1);
        }
    }

    vector<int> ans;
    FOR(i, 1, n + 1) {
        if (check[i].count() == red_cnt && visited_di[i] == 0) {
            ans.push_back(i);
        }
    }

    if(red_cnt){
        cout << ans.size() << endl;
        FOR(i, 0, ans.size()) {
            cout << ans[i] << ' ';
        }
    }else{
        cout << n << endl;
        FOR(i,1,n+1) cout << i << ' ';
    }
}

int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //write your code here
    solve();

    return 0;
}