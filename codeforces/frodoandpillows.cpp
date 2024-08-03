#include <bits/stdc++.h>

using namespace std;

int main () {
    long long int n, m, k;
    scanf ("%lld%lld%lld", &n, &m, &k);
    long long int antes = k-1, depois = n-k;
    long long int l=1, r=m, mid, ans;
    while (l<=r) {
        mid = (l+r)/2;
        long long int soma_min = mid;
        if (antes<mid) soma_min += (antes*(mid-antes+mid-1))/2;
        else soma_min += ((mid-1)*mid)/2 + (antes-mid+1);
        if (depois<mid) soma_min += (depois*(mid-depois+mid-1))/2;
        else soma_min += ((mid-1)*mid)/2 + (depois-mid+1);
        if (soma_min<=m) {
            ans = mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    printf ("%lld\n", ans);
    return 0;
}
