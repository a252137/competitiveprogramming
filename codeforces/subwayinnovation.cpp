#include <bits/stdc++.h>

using namespace std;

long long int vet[300010], pref[300010];

int main () {
    
    int n; 
    scanf ("%d", &n);
    
    vector<pair<long long int, int>> pos;
    
    for (int i=1; i<=n; i++) {
        
        scanf ("%lld", &vet[i]);
        pos.push_back({vet[i], i});
        
    }
    
    int k;
    scanf ("%d", &k);
    
    sort (vet+1, vet+n+1);
    sort (pos.begin(), pos.end());
    
    pref[1]=vet[1];
    
    for (int i=2; i<=n; i++) pref[i]=pref[i-1]+vet[i];
    
    int ans = 1;
    long long int mini = 0;
    
    for (int i=1; i<=k; i++) {
        
        mini += (i-1)*vet[i];
        mini -= pref[i-1];
        
    }
    
    long long int aux = mini;
    
    for (int i=2; i<=n-k+1; i++) {
        
        aux = aux + k*vet[i-1] - (pref[i+k-2] - pref[i-2]) + k*vet[i+k-1] - (pref[i+k-1]-pref[i-1]);
        
        if (aux<mini) {
            
            ans = i;
            mini = aux;
            
        }
        
    }
    
    for (int i=ans-1; i<=ans+k-2; i++) {
        
        printf("%d ", pos[i].second);
        
    }
    
    printf ("\n");
    
}







