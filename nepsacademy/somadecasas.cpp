#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf ("%d", &n);
    int vet[100010];
    for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
    int k;
    scanf ("%d", &k);
    for (int i=1; i<=n; i++) {
        int l = 1, r = n, mid, ans = -1;
        while (l<=r) {
            mid = (l+r)/2;
            if (vet[mid] + vet[i] == k) {
                ans = mid;
                break;
            }
            else if (vet[mid] + vet[i] > k) r = mid - 1;
            else if (vet[mid] + vet[i] < k) l = mid + 1;
        }
        if (ans == i) continue;
        if (ans != -1) {
            printf ("%d %d\n", min(vet[mid], vet[i]), max(vet[mid], vet[i]));
            break;
        }
    }
    return 0;
}