#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    cout<<fixed;
    cout.precision(1);
    float ans = 0;
    if(s[0] == 'A'){
        ans += 4;
    } else if(s[0] == 'B'){
        ans += 3;
    } else if(s[0] == 'C'){
        ans += 2;
    } else if(s[0] == 'D'){
        ans += 1;
    } else{
        cout << ans << endl;
        return 0;
    }
    if(s[1] == '+'){
        ans += 0.3;
    } else if(s[1] == '-'){
        ans -= 0.3;
    }
    cout << float(ans) << endl;
    return 0;
}