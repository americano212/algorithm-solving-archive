#include <iostream>

// https://www.acmicpc.net/problem/2018

using namespace std;

int main(){
    int n;
    cin >> n;
    int x=1, y=1, sum=1;
    int result = 1;
    while(1){
        if(x == y && y == n){
            break;
        }
        if(sum == n){
            // cout << x << " " << y << endl;
            result += 1;
        }
        if(sum <= n || x == y){
            y += 1;
            sum += y;
        } else{
            sum -= x;
            x += 1;
        }
    }
    cout << result << endl;
}