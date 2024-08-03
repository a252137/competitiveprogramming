#include <bits/stdc++.h>
 
using namespace std;
 
int vet[200010];
 
int main() {
    int n;
    scanf ("%d", &n);
    for (int i=1; i<n; i++) {
        int x;
        scanf ("%d", &x);
        vet[x] = 1;
    }
    for (int i=1; i<=n; i++) {
        if (vet[i]!=1) {
            printf ("%d\n", i);
            break;
        }
    }
    return 0;

