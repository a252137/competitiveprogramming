#include <bits/stdc++.h>
#define MAXN 100010
#define lli long long int

using namespace std;

int main () {
    int n;
    lli s;
    scanf ("%d%lld", &n, &s);
    int v[MAXN];
    for (int i=1; i<=n; i++) scanf ("%d", &v[i]);
    int l=1;
    lli ans = 0, atual = 0;
    for (int r=1; r<=n; r++) {
        atual += v[r];
        while (atual-v[l]>=s) {
            atual -= v[l];
            l++;
        }
        if (atual>=s) ans += l;
    }
    printf ("%lld\n", ans);
    return 0;
}