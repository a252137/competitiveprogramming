#include <bits/stdc++.h>

using namespace std;

int vet[100010];
int soma[100010];
int freq[20];
int mud[100010];

int main() {
    
    int n, m;
    scanf ("%d%d", &n, &m);
    
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    
    for (int i=1; i<=m; i++) scanf ("%d", &mud[i]);
    
    for (int i=2; i<=m; i++) {
        
        if (mud[i-1]<mud[i]) {
            
            soma[mud[i-1]+1]++;
            soma[mud[i]]--;
            
        }
        
        else {
            
            soma[mud[i]+1]++;
            soma[mud[i-1]]--;
            
        }
        
    }
    
    for (int i=1; i<=n; i++) soma[i]+=soma[i-1];
    
    for (int i=1; i<=m; i++) soma[mud[i]]++;
    
    for (int i=1; i<=n; i++) {
        
        freq[vet[i]]+=soma[i];
        
    }
    
    for (int i=0; i<=9; i++) printf ("%d ", freq[i]);
    
    printf ("\n");
    
    return 0;
    
}
