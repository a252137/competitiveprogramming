#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
const int raiz = 320;

int vet[maxn], meuBloco[maxn], ini[raiz], fim[raiz];
int prox[maxn], movimento[maxn];

void decomp (int bloco) {

    for (int i=fim[bloco]; i>=ini[bloco]; i--) {

        if (i+vet[i]>fim[bloco]) prox[i]=vet[i]+i;
        else prox[i]=prox[i+vet[i]];

        if (vet[i]+i>fim[bloco]) movimento[i]=1;
        else movimento[i]=movimento[i+vet[i]]+1;

    }

}

int main() {

    int n, m;
    scanf ("%d%d", &n, &m);

    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);

    int sqr = sqrt(n)+1;

    for (int i=1, j=sqr, k=0; i<=n; i++, j++) {

        if (j==sqr) {

            k++;
            ini[k]=i;
            j=0;

        }

        meuBloco[i]=k;
        fim[k]=i;

    }

    for (int i=1; i<=meuBloco[n]; i++) decomp(i);

    for (int i=1; i<=m; i++) {

        int a, b, c;

        scanf ("%d", &a);

        if (a==0) {

            scanf ("%d%d", &b, &c);
            vet[b]=c;
            decomp(meuBloco[b]);

        }

        else {

            scanf ("%d", &b);

            int last=0, mov=0;

            while (prox[b]<=n) {

                mov += movimento[b];
                b=prox[b];

            }

            while (vet[b]+b<=n) {

                mov++;
                b+=vet[b];

            }

            printf ("%d %d\n", b, mov+1);

        }

    }


}

