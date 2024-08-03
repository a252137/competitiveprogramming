#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int x, y;
        scanf ("%d%d", &x, &y);
        long long int tam = (x-y)*2;
        printf ("%lld\n", tam);
        int at = x;
        for (int i=1; i<=(x-y); i++) {
            printf ("%d ", at);
            at--;
        }
        for (int i=1; i<=(x-y); i++) {
            printf ("%d ", at);
            at++;
        }
        printf ("\n");
    }
    return 0;
}
