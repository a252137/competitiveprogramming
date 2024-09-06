#include <bits/stdc++.h>
#define MAXN 100010
#define lli long long int

using namespace std;

int freq[MAXN], v[MAXN];

int main () {
    int n, k;
    scanf ("%d%d", &n, &k);
    for (int i=1; i<=n; i++) scanf ("%d", &v[i]);
    int l=1, num = 0;
    lli ans = 0;
    for (int r=1; r<=n; r++) {
        freq[v[r]]++;
        if (freq[v[r]]==1) num++;
        while (num>k) {
            freq[v[l]]--;
            if (freq[v[l]]==0) num--;
            l++;
        }
        ans += r-l+1;
    }
    printf ("%lld\n", ans);
    return 0;
}