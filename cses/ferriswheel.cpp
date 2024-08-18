#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

int main () {
    int n, x;
    scanf ("%d%d", &n, &x);
    int vet[MAXN];
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    sort(vet+1, vet+n+1);
    int l=1, r=n;
    int ans = 0;
    while (l<=r) {
        if (l==r) {
            ans++;
            break;
        }
        if (vet[l]+vet[r]<=x) {
            ans++;
            l++;
            r--;
        }
        else {
            ans++;
            r--;
        }
    }
    printf ("%d\n", ans);
    return 0;
}