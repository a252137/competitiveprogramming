#include <bits/stdc++.h>
 
using namespace std;
 
int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n, m;
        scanf ("%d%d", &n, &m);
        map<char, int> dif;
        int ans = 0;
        for (int i=1; i<=n; i++) {
            char c;
            scanf (" %c", &c);
            dif[c]++;
        }
        for (int i=65; i<=71; i++) {
            if (dif[i]<m) ans += m-dif[i];
        }
        dif.clear();
        printf ("%d\n", ans);
    }
    return 0;
}
