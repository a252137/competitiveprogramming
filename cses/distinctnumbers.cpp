#include <bits/stdc++.h>
 
using namespace std;
 
int vet[200010];
 
int main() {
    int n;
    scanf ("%d", &n);
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    sort (vet+1, vet+n+1);
    int ans = 1;
    for (int i=2; i<=n; i++) {
        if (vet[i] != vet[i-1]) ans++;
    }
    printf ("%d\n", ans);
    return 0;
}
