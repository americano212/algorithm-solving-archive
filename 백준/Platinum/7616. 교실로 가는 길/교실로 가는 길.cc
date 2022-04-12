#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define pb push_back
//#define int long long
#define so sizeof
#define MAX 5001
#define INF 987654321


using namespace std;

bool c[MAX][MAX],f[MAX][MAX],vis[MAX],tmp[MAX],ar[MAX],chk[MAX];
 
int main()
{
    int n, p, tc = 1;
 
    while (1)
    {
        memset(c, 0, so(c));
        memset(f, 0, so(f));
        memset(vis, false, so(vis));
        memset(tmp, false, so(tmp));
        memset(ar, false, so(ar));
        stack<int> st;
 
        vector<int> adj[MAX];

        cin >> n >> p;
        if (n == 0 && p == 0)
            break;
 
        for (int i = 1; i <= p; i++)
        {
            memset(chk, false, so(chk));
 
            while (1)
            {
                int to;char ch;
                scanf("%d%c", &to,&ch);
                if(!ar[i])
                    ar[i] = true;
 
                if (!ar[to])
                {
                    if (!chk[to])
                    {
                        chk[to] = true;
                        c[i][to] = 1;
                        c[to][i] = 1;
 
                        adj[i].pb(to);
                        adj[to].pb(i);
                    }
                }
                if (ch == '\n')
                    break;
            }
        }
        
        int all = 0, S = 1, T = 2;
        while (1)
        {
            int prev[MAX];
            memset(prev, -1, so(prev));
 
            queue<int> q;
            q.push(S);
 
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
 
                if (cur != S && cur != T)
                    vis[cur] = true;
 
                for (int i = 0; i < adj[cur].size(); i++)
                {
                    int next = adj[cur][i];

                    if (prev[next] != -1 || next == S)
                        continue;
                    if (!vis[next] && c[cur][next] - f[cur][next] > 0)
                    {
                        q.push(next);
 
                        prev[next] = cur;
 
                        if (next == T)
                            break;
                    }
                }
            }
 
            memset(vis, false, so(vis));
 
            if (prev[T] == -1)
                break;
            memcpy(vis, tmp, so(tmp));
 
            for (int i = T; i != S; i = prev[i])
            {
                st.push(i);
                f[prev[i]][i] = 1;
                f[i][prev[i]] = 0;
 
                if (i != S && i != T)
                    vis[i] = true;
            }
 
            memcpy(tmp, vis, so(vis));
 
            st.push(1);
 
            all ++;
        }
 
        printf("Case %d:\n", tc++);
        if (all >= n)
        {
            while (!st.empty() && n)
            {
                cout << st.top() << ' ';
                if (st.top() == 2)
                {
                    n--;
                    cout << endl;
                }
                st.pop();
            }
        }
 
        else
            cout << "Impossible" << endl;
 
        cout << endl;
    }
 
    return 0;
}
