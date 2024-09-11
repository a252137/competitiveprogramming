#include <bits/stdc++.h>
#define MAXN 1010
#define lli long long int

using namespace std;

int main () {
    int n;
    lli p;
    scanf ("%d%lld", &n, &p);
    lli vet[2*MAXN];
    lli soma = 0, maxi = 0;
    int ind_maxi = 0;
    for (int i=1; i<=n; i++) {
        scanf ("%lld", &vet[i]);
        soma+=vet[i];
        if (vet[i]>maxi) {
            maxi = vet[i];
            ind_maxi = i;
        }
    }
    lli ans = 2*n;
    for (int i=n+1; i<=2*n; i++) vet[i] = vet[i-n];
    lli divisao = 0;
    if (soma<=p) {
        divisao = p/soma;
        p -= soma*divisao;
        divisao = n*divisao;
        if (p<=0) {
            printf ("%d %lld\n", ind_maxi, divisao);
            return 0;
        }
    }
    int l=1;
    lli atual = 0;
    for (int r=1; r<=2*n; r++) {
        atual += vet[r];
        while (atual-vet[l]>=p) atual -= vet[l++];
        if (l>n) break;
        if (atual>=p) {
            if (r-l+1<ans) {
                ans = r-l+1;
                ind_maxi = l;
            }
        }
    }
    printf ("%d %lld\n", ind_maxi, ans+divisao);
    return 0;
}