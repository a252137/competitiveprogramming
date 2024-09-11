#include <bits/stdc++.h>
#define MAXN 1000010

using namespace std;

int main () {
    int n, d;
    scanf ("%d%d", &n, &d);
    int vet[2*MAXN];
    int atual=0;
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    for (int i=n+1; i<=2*n; i++) vet[i] = vet[i-n];
    int l = 1;
    long long int ans = 0;
    for (int r=1; r<=2*n; r++) {
        atual += vet[r];
        while (atual>d) atual -= vet[l++];
        if (l>n) break;
        if (r-l+1>n) continue;
        if (atual==d) ans++;
    }
    printf ("%lld\n", ans);
    return 0;
}