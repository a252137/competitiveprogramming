#include <bits/stdc++.h>
 
using namespace std;
 
int vet[200010];
 
int main() {
    int n;
    scanf ("%d", &n);
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    sort (vet+1, vet+n+1);
    long long int mediana;
    if (n%2 == 0) mediana = (vet[n/2]+vet[(n/2)+1])/2;
    else mediana = vet[(n/2)+1];
    long long int ans = 0;
    for (int i=1; i<=n; i++) ans += abs(vet[i]-mediana);
    printf ("%lld\n", ans);
    return 0;
}
