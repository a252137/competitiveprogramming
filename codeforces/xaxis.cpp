#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c);
        int ans = 100;
        for (int i=1; i<=10; i++) {
            ans = min(ans, abs(a-i)+abs(b-i)+abs(c-i));
        }
        printf ("%d\n", ans);
    }
    return 0;
}
