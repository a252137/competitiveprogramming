#include <bits/stdc++.h>

using namespace std;

long long int vet[200010], soma[200010];

int main () {
    int n, q;
    scanf ("%d%d", &n, &q);
    for (int i=1; i<=n; i++) scanf ("%lld", &vet[i]);
    for (int i=1; i<=n; i++) soma[i] = soma[i-1] + vet[i];
    while (q--) {
        int a, b;
        scanf ("%d%d", &a, &b);
        printf ("%lld\n", soma[b]-soma[a-1]);
    }
    return 0;
}