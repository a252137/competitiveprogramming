#include <bits/stdc++.h>

using namespace std;

int vet[200010], ord[200010];

int main () {
    int n, x;
    scanf ("%d%d", &n, &x);
    int aux = 0;
    for (int i=1; i<=n; i++) {
        scanf ("%d", &vet[i]);
        ord[i]=vet[i];
        if (vet[i]==x/2) aux++;
    }
    if (x%2==0 && aux>=2) {
        int k = 0;
        for (int i=1; i<=n; i++) {
            if (vet[i]==x/2) {
                printf ("%d ", i);
                k++;
            }
            if (k==2) break;
        }
        printf ("\n");
        return 0;
    }
    sort(ord+1, ord+n+1);
    int ans1 = -1, ans2 = -1;
    for (int i=1; i<=n; i++) {
        if (x%2==0 && ord[i]==x/2) continue;
        int l=1, r=n, mid;
        while (l<=r) {
            mid = (l+r)/2;
            if (ord[mid]+ord[i]==x) {
                ans1=ord[i];
                ans2=ord[mid];
                break;
            }
            else if (ord[mid]+ord[i]<x) l=mid+1;
            else r=mid-1;
        }
        if (ans1!=-1) break;
    }
    if (ans1==-1) printf ("IMPOSSIBLE\n");
    else {
        int k1=0, k2=0;
        for (int i=1; i<=n; i++) {
            if (vet[i]==ans1 && k1==0) {
                printf ("%d ", i);
                k1++;
            }
            if (vet[i]==ans2 && k2==0) {
                printf ("%d ", i);
                k2++;
            }
            if (k1==1 && k2==1) break;
        }
        printf ("\n");
    }
    return 0;
}