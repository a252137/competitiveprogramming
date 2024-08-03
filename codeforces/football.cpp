#include <bits/stdc++.h>

using namespace std;

int main () {
    
    string s;
    cin>>s;
    
    int cont = 1;
    bool check = false;
    
    for (int i=1; i<(int)s.size(); i++) {
        
        if (s[i]==s[i-1]) cont++;
        else {
            
            if (cont>=7) check = true;
            cont=1;
            
        }
        
    }
    
    if (cont>=7) check = true;
    
    if (check==true) printf ("YES\n");
    else printf ("NO\n");
    
}
