#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
        if(65 <= s[i] && s[i] <=90){
            cout << char(s[i] + 32);
        } else{
            cout << char(s[i] - 32);
        }
    }
    cout << endl;
}