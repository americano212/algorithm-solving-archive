#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n, m;
    cin >> n >> m;
    vector< vector<int> > matrix(n, vector<int>(m, 0));
    int tmp;
    for(int i=0; i<2;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin >> tmp;
                matrix[j][k] += tmp;
            }
        }
    }
    for(int j=0;j<n;j++){
        for(int k=0;k<m;k++){
            cout << matrix[j][k] << " ";
        }
        cout << "\n";
    }
}