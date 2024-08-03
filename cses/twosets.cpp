#include <bits/stdc++.h>
 
using namespace std;
 
int main () {
    
    int n;
    scanf ("%d", &n);
    
    vector<int> esq;
    vector<int> dir;
    long long int soma1 = 0;
    long long int soma2 = 0;
    
    for (int i=n; i>=1; i--) {
        
        if (soma1>soma2) {
            
            dir.push_back(i);
            soma2+=i;
            
        }
        
        else {
            
            esq.push_back(i);
            soma1+=i;
            
        }
        
    }
    
    if (soma2!=soma1) {
        
        printf ("NO\n");
        return 0;
        
    }
    
    printf ("YES\n");
    
    sort (esq.begin(), esq.end());
    
    sort (dir.begin(), dir.end());
    
    printf ("%d\n", (int)esq.size());
    
    for (int i=0; i<(int)esq.size(); i++) printf ("%d ", esq[i]);
    
    printf ("\n");
    
    printf ("%d\n", (int)dir.size());
    
    for (int i=0; i<(int)dir.size(); i++) printf ("%d ", dir[i]);
    
    printf ("\n");
    
    return 0;
    
}
