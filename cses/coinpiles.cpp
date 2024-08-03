#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int a, b;
        scanf ("%d%d", &a, &b);
        long long int y = 2*b-a, x = 2*a-b;
        if ((a==0 && b!=0) || (a!=0 && b==0)) printf ("NO\n");
        else if (y%3!=0 || x%3!=0) printf ("NO\n");
        else if (y<0 || x<0) printf ("NO\n");
        else printf ("YES\n");
    }
    return 0;
}