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
    lli atual = 0, ans = 0;
    for (int r=1; r<=n; r++) {
        atual += v[r];
        while (atual>s) {
            atual-=v[l];
            l++;
        }
        ans += r-l+1;
    }
    printf ("%lld\n", ans);
    return 0;
}