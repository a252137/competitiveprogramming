#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    int vet[10010];
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    if (m-vet[1]<vet[1]) vet[1] = m - vet[1];
    long long int ans = vet[1];
    for (int i=2; i<=n; i++) {
        if (m-vet[i]>=vet[i-1] && vet[i]<vet[i-1]) vet[i] = m-vet[i];
        else if (m-vet[i]<vet[i] && m-vet[i]>=vet[i-1]) vet[i] = m-vet[i];
        if (vet[i]<vet[i-1]) {
            ans = -1;
            break;
        }
        ans += vet[i];
    }
    printf ("%lld\n", ans);
    return 0;
}