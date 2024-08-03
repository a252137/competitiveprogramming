#include <bits/stdc++.h>

using namespace std;

int main () {
    int v;
    scanf ("%d", &v);
    int ans = 0;
    int atual[6] = {100, 50, 25, 10, 5, 1};
    for (int i=0; i<6; i++) {
        ans += v/atual[i];
        v -= (v/atual[i]) * atual[i];
    }
    printf ("%d\n", ans);
    return 0;
}