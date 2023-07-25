#include <bits/stdc++.h>
// https://www.acmicpc.net/problem/7785
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, int> name_set;
    vector<string> result;

    while(n--){
        string name, state;
        cin >> name >> state;
        if(state == "enter"){
            name_set[name] = 1;
        }else{
            name_set[name] = 0;
        }

        
    }
    for(auto item : name_set){
        if(item.second){
            result.push_back(item.first);
        }
    }
    sort(result.rbegin(), result.rend());
    for(auto item: result){
        cout << item << '\n';
    }
}