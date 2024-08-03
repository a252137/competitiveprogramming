#include <bits/stdc++.h>

using namespace std;

const int maxn=2010;

int peso[maxn], prot[maxn], dp[maxn][maxn];

int main() {

    int p, n;
    scanf ("%d%d", &p, &n);

    for (int i=1; i<=n; i++) scanf ("%d%d", &peso[i], &prot[i]);

    // dp[i][j] = quantidade maxima de proteina que conseguimos
    // com i pedaços e j de peso

    for (int i=1; i<=n; i++) {

        for (int j=1; j<=p; j++) {

            int caso1=0, caso2=0;

            if (j-peso[i]>=0) {

                caso1 = dp[i-1][j-peso[i]]+prot[i];

            }

            caso2 = dp[i-1][j];

            dp[i][j]=max(caso2, caso1);

        }

    }

    printf ("%d\n", dp[n][p]);

}

