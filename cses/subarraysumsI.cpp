#include <bits/stdc++.h>
#define MAXN 200010
#define lli long long int

using namespace std;

int main () {
    int n;
    lli x;
    scanf ("%d%lld", &n, &x);
    lli v[MAXN];
    for (int i=1; i<=n; i++) scanf ("%lld", &v[i]);
    int l=1;
    lli ans = 0, atual = 0;
    for (int r=1; r<=n; r++) {
        atual += v[r];
        while (atual>x) {
            atual-=v[l];
            l++;
        }
        if (atual == x) ans++;
    }
    printf ("%lld\n", ans);
    return 0;
}