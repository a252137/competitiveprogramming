#include <bits/stdc++.h>

using namespace std;

int main () {
    
    int t;
    scanf ("%d", &t);
    
    while (t--) {
        
        int n;
        vector<int> impar;
        vector<int> par;
        scanf ("%d", &n);
        
        if (n==2) {
            
            printf ("-1\n");
            continue;
            
        }
        
        for (int i=1; i<=n*n; i++) {
            
            if (i%2==0) par.push_back(i);
            else impar.push_back(i);
            
        }
        
        int i;
        
        for (i=0; i<(int)impar.size(); i++) {
            
            printf ("%d ", impar[i]);
            if ((i+1)%n==0) printf ("\n");
            
        }
        
        for (int j=0; j<(int)par.size(); j++, i++) {
            
            printf ("%d ", par[j]);
            if ((i+1)%n==0) printf ("\n");
            
        }
        
    }
    
}
