#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>

#define ll long long
using namespace std;
int i,j,k;
int n,m;
int G;
int r,c;
string L[21];
void dfs(int x,int y,int* check,int cnt){
	if (check[L[x][y]-65]==1){
		G = max(G,cnt);
		return;
	}
	else{
		check[L[x][y]-65]= 1;
		cnt+=1;
		
		if (x!=0){
			dfs(x-1,y,check,cnt);
		}
		if (y!=0){
			dfs(x,y-1,check,cnt);
		}
		if (x!=r-1){
			dfs(x+1,y,check,cnt);
		}
		if (y!=c-1){
			dfs(x,y+1,check,cnt);
		}
	}
	check[L[x][y]-65]= 0;
}

int main(){
	
	cin >> r >> c;
	
	for (i=0;i<r;i++){
		cin >> L[i];
	}
	int check[26]={0,};
	dfs(0,0,check,0);
	cout << G;
	
}