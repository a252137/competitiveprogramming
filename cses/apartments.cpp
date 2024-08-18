#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

int main () {
    int n, m, k;
    scanf ("%d%d%d", &n, &m, &k);
    int vet[MAXN], apt[MAXN];
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    for (int i=1; i<=m; i++) scanf ("%d", &apt[i]);
    sort(vet+1, vet+n+1);
    sort(apt+1, apt+m+1);
    int ind = 1;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        bool check = false;
        if (ind>m) break;
        while (apt[ind]<=vet[i]) {
            if (abs(vet[i]-apt[ind])<=k) {
                ans++;
                ind++;
                check = true;
                break;
            }
            ind++;
        }
        if (check == true) continue;
        if (abs(vet[i]-apt[ind])<=k) {
            ans++;
            ind++;
        }
    }
    printf ("%d\n", ans);
    return 0;
}