#include <bits/stdc++.h>
#define MAXN 1000010

using namespace std;

int resp[MAXN];

int main () {
    int n, k;
    scanf ("%d%d", &n, &k);
    int vet[110];
    for (int i=1; i<=k; i++) scanf ("%d", &vet[i]);
    sort (vet+1, vet+k+1);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            if (vet[j]>i) break;
            if (resp[i-vet[j]]==0) {
                resp[i] = 1;
                break;
            }
        }
        if (resp[i]==1) printf ("W");
        else printf ("L");
    }
    printf ("\n");
    return 0;
}