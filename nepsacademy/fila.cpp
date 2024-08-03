#include <bits/stdc++.h>

using namespace std;

vector<int> vet;
int ident[100010], n, m, i;

int main() {
    
    scanf ("%d", &n);
    
    for (i=0; i<n; i++) {
        
        int x;
        
        scanf ("%d", &x);
        
        vet.push_back(x);
        
    }
    
    scanf ("%d", &m);
    
    for (i=0; i<m; i++) {
        
       int y;
       
       scanf ("%d", &y);
       
       ident[y]=1;

    }
    
    for (i=0; i<n; i++) {
        
        if (ident[vet[i]]==1) continue;
        
        printf ("%d ", vet[i]);
        
    }
    
    printf ("\n");
    
    return 0;
    
}






