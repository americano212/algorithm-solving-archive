#include <bits/stdc++.h>
#define btw(n, x, y) x <= n &&n < y
#define pii pair<int, int>
using namespace std;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};

int find(int x, vector<int> &parent) {
    if (x == parent[x])
        return x;

    return parent[x] = find(parent[x], parent);
}

// 두 node 연결
void merge(int x, int y, vector<int> &parent) {
    int a = find(x, parent);
    int b = find(y, parent);
    if (a == b)
        return;

    parent[a] = b;
}

// 두 node 간 연결성 판정
bool isUnion(int x, int y, vector<int> &parent) {
    int a = find(x, parent);
    int b = find(y, parent);

    return a == b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pii> v(n);
    int a, b;


    vector<int> parent(n + 1);
    for (int i = 0; i < n + 1; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n - 2; i++) {
        cin >> a >> b;
        merge(a, b, parent);
    }

    for (int i = 2; i < n + 1; i++) {
        if (isUnion(1, i, parent) == false) {
            cout << 1 << ' ' << i << endl;
            return 0;
        }
    }
}
