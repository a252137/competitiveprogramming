#include <bits/stdc++.h>

using namespace std;

int main () {
    char c[1000010], ans[1000010];
    scanf ("%s", c);
    int n = strlen(c);
    map<char, int> cont;
    for (int i=0; i<n; i++) cont[c[i]]++;
    bool impar = false;
    char meio;
    for (int i=65; i<=90; i++) {
        if (cont[i]%2==1 && n%2==0) {
            printf ("NO SOLUTION\n");
            return 0;
        }
    }
    int aux = 1;
    for (int i=65; i<=90; i++) {
        if (cont[i]%2==0) {
            while (cont[i]>0) {
                ans[aux] = i;
                ans[n-aux+1] = i;
                cont[i] -= 2;
                aux++;
            }
        }
        else {
            if (impar == true) {
                printf ("NO SOLUTION\n");
                return 0;
            }
            impar = true;
            meio = i;
            while (cont[i]>1) {
                ans[aux] = i;
                ans[n-aux+1] = i;
                cont[i] -= 2;
                aux++;
            }
        }
    }
    if (n%2==1) ans[aux] = meio;
    for (int i=1; i<=n; i++) printf ("%c", ans[i]);
    printf ("\n");
    return 0;
}