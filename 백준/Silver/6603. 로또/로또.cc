#define ll long long
#include <iostream>
#include <vector>
#include <string>

using namespace std;

ll X,Y,x,y,N,M,a,b,t;
int k;
int v[13];
int prt[6];

void solve(int idx, int depth){
    if(depth==6){
        for (int i = 0; i < 6; i++) {
			cout << prt[i] << " ";
		}
		cout << endl;
		return;
    }
    for (int i = idx; i < k; i++)
    {
        prt[depth] = v[i];
        solve(i+1, depth+1);
    }
}

int main() {
    
    while(true){
        cin >> k;
        if(k==0) break;
        for (int i = 0; i < k; i++)
        {
            cin >> v[i];
        }
        
        solve(0,0);
        cout << endl;
    }

    
    return 0;
}