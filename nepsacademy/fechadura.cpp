#include <bits/stdc++.h>

using namespace std;

int vet[1010];
int ans;

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    for (int i=1; i<n; i++) {
        if (vet[i]==m) continue;
        ans += abs(m-vet[i]);
        vet[i+1] += m-vet[i];
    }
    printf ("%d\n", ans);
    return 0;
}
