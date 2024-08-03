#include <bits/stdc++.h>

using namespace std;

long long int f[1010], a[1010];
int n, m;

long long int recursao (int k) {
    if (f[k]!=-1) return f[k];
    f[k] = 0;
    for (int i=1; i<=n; i++) {
        if (f[k-i] == -1) f[k-i] = recursao(k-1);
        f[k] += a[i]*f[k-i];
        f[k] = f[k]%m;
    }
    return f[k]%m;
}

int main () {
    int k;
    scanf ("%d%d%d", &n, &k, &m);
    for (int i=1; i<=n; i++) scanf ("%lld", &a[i]);
    for (int i=1; i<=n; i++) scanf ("%lld", &f[i]);
    for (int i=n+1; i<=k; i++) f[i] = -1;
    printf ("%lld\n", recursao(k));
    return 0;
}