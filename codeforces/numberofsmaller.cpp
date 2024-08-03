#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    scanf ("%d%d", &n, &m);

    int vet[100010], vec[100010];

    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);

    for (int i=1; i<=m; i++) scanf ("%d", &vec[i]);

    int i=1, j=1, k=1;

    vet[n+1]=1000000010;
    vec[m+1]=1000000010;

    while (i<=n || j<=m) {

        if (j>m || (i<=n && vet[i]<vec[j])) {

            i++;

        }

        else {

            printf ("%d ", i-1);
            j++;

        }

    }

    printf ("\n");

}

