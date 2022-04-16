#include <cstdio>
#include <algorithm>

#include <vector>

#include <string>
#include <iostream>
#include <map>
using namespace std;
int t;


vector<int> L;
vector<int> r;

string a, w, s;

void get_pi(string b) {
    L.clear();
    L.resize(b.length());
    int j = 0;
    for (int i = 1; i < b.length(); i++) {
        while (j > 0 && b[i] != b[j])
            j = L[j - 1];       
        if (b[i] == b[j])
            L[i] = ++j;     
    }
}
int kmp(string a, string b) {
    int j = 0;
    
    int out = 0;
    
    for (int i = 0; i < a.length(); i++) {
    	
        while (j > 0 && a[i] != b[j])
            j = L[j - 1];
            
        if (a[i] == b[j]) {
        	
            if (j == b.length() - 1) {
                out++;
                j = L[j];
            }
            
            else
                j++;
        }
    }
    return out;
}

map<char, int> mp;
map<int, char> rmp;
int i,j;
int main() {
	
    cin >> t;
    
    while (1) {
    	
    	if (t==0) break;
    	
        cin >> a >> w >> s;
        int n = a.length();
        
        r.clear();
        
        for (i = 0; i < n; i++) {
            mp[a[i]] = i;
            rmp[i] = a[i];
        }
        for (i = 0; i < n; i++) {
            if (i) {
                for (j = 0; j < w.length(); j++) {
                    w[j] = rmp[(mp[w[j]] + 1) % n];
                }
            }
            get_pi(w);
            if (kmp(s, w) == 1)
                r.push_back(i);
        }
        if (!r.size())
            printf("no solution\n");
        else if (r.size() == 1)
            printf("unique: %d\n", r[0]);
        else {
            printf("ambiguous: ");
            for (int x : r)
                printf("%d ", x);
            printf("\n");
        }
        t--;
    }
    return 0;
}