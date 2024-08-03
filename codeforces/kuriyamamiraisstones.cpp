#include <bits/stdc++.h>

using namespace std;

int vet[100010];
int ord[100010];
long long int soma1[100010];
long long int soma2[100010];

int main() {
    
    int n;
    scanf ("%d", &n);
    
    for (int i=1; i<=n; i++) {
        
        scanf ("%d", &vet[i]);
        ord[i]=vet[i];
        
    }
    
    sort (ord+1, ord+n+1);
    
    for (int i=1; i<=n; i++) soma1[i]=soma1[i-1]+vet[i];
    
    for (int i=1; i<=n; i++) soma2[i]=soma2[i-1]+ord[i];
    
    int m;
    scanf ("%d", &m);
    
    for (int i=1; i<=m; i++) {
        
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c);
        
        if (a==1) printf ("%lld\n", soma1[c]-soma1[b-1]);
        
        else printf ("%lld\n", soma2[c]-soma2[b-1]);
        
    }
    
    return 0;
    
}
