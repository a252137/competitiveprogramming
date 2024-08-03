#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    scanf ("%d", &t);
    
    int vet[110];
    
    int freq[110];
    
    while (t--) {
        
        int n;
        scanf ("%d", &n);
        
        for (int i=1; i<=100; i++) freq[i]=0;
        
        for (int i=1; i<=n; i++) {
            
            scanf ("%d", &vet[i]);
            freq[vet[i]]++;
            
        }
        
        for (int i=1; i<=n; i++) {
            
            if (freq[vet[i]]==1) {
                
                printf ("%d\n", i);
                break;
                
            }
            
        }
        
    }
    
    return 0;
    
}
