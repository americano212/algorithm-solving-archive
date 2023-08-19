#include <bits/stdc++.h>

#define endl '\n';
#define INF 2147483647;
using namespace std;
typedef long long int ll;
typedef vector<vector<ll>> matrix;

const ll mod = 1000000007LL;

ll a, b, c, i, j, k, n, m, t;
ll test;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<int> graph_1[501], graph_2[501];
    priority_queue<int, vector<int>, greater<int>> pq;

    while (m--)
    {
        cin >> a >> b;
        graph_1[a].push_back(b);
        graph_2[b].push_back(a);
    }

    ll result = 0;

    for (int start_node = 1; start_node < n + 1; start_node++)
    {
        vector<int> visit_1(501, 0);
        pq.push(start_node);

        while (!pq.empty())
        {
            int now_node;
            now_node = pq.top();
            pq.pop();
            if (visit_1[now_node] == 1)
            {
                continue;
            }
            visit_1[now_node] = 1;
            for (auto next_node : graph_1[now_node])
            {
                if (visit_1[next_node] == 0)
                {
                    pq.push(next_node);
                }
            }
        }
        vector<int> visit_2(501, 0);
        pq.push(start_node);
        while (!pq.empty())
        {
            int now_node;
            now_node = pq.top();
            pq.pop();
            if (visit_2[now_node] == 1)
            {
                continue;
            }
            visit_2[now_node] = 1;
            for (auto next_node : graph_2[now_node])
            {
                if (visit_2[next_node] == 0)
                {
                    pq.push(next_node);
                }
            }
        }
        int temp_cnt = 0;
        for (j = 1; j < n + 1; j++)
        {
            if (visit_1[j] | visit_2[j])
            {
                temp_cnt += 1;
            }
        }
        if (temp_cnt == n)
        {
            result += 1;
        }
    }
    cout << result << endl;
}