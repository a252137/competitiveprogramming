#include <bits/stdc++.h>

using namespace std;

int main () {
    
    int n;
    scanf ("%d", &n);
    
    int nP=0, nM=0;
    
    for (int i=1; i<=n; i++) {
        
        int a;
        scanf ("%d", &a);
        
        if (a==1) nP++;
        else nM++;
        
    }
    
    int P, M;
    scanf ("%d%d", &P, &M);
    
    if (P==nP && M==nM) printf ("S\n");
    else printf ("N\n");
    
    return 0;
    
}
