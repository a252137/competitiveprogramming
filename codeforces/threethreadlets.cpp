#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf ("%d", &t);
    while (t--) {
        
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c);
        
        if (a==b && a==c) {
            printf ("YES\n");
            continue;
        }
        
        if (a<=b && a<=c) {
            if (a==b) {
                if ((c-a)%a==0 && (c-a)/a<=3) {
                    printf ("YES\n");
                }
                else printf ("NO\n");
            }
            else if (a==c) {
                if ((b-a)%a==0 && (b-a)/a<=3) {
                    printf ("YES\n");
                }
                else printf ("NO\n");
            }
            else {
                if (((b-a)%a==0 && (c-a)%a==0) && ((b-a)/a)+((c-a)/a)<=3) printf ("YES\n");
                else printf ("NO\n");
            }
        }
        
        else if (b<=a && b<=c) {
            if (a==b) {
                if ((c-a)%a==0 && (c-a)/a<=3) {
                    printf ("YES\n");
                }
                else printf ("NO\n");
            }
            else if (b==c) {
                if ((a-b)%b==0 && (a-b)/b<=3) {
                    printf ("YES\n");
                }
                else printf ("NO\n");
            }
            else {
                if (((a-b)%b==0 && (c-b)%b==0) && ((a-b)/b)+((c-b)/b)<=3) printf ("YES\n");
                else printf ("NO\n");
            }
        }
        
        else if (c<=b && c<=a) {
            if (a==c) {
                if ((b-a)%a==0 && (b-a)/a<=3) {
                    printf ("YES\n");
                }
                else printf ("NO\n");
            }
            else if (b==c) {
                if ((a-c)%c==0 && (a-c)/c<=3) {
                    printf ("YES\n");
                }
                else printf ("NO\n");
            }
            else {
                if (((b-c)%c==0 && (a-c)%c==0) && ((b-c)/c)+((a-c)/c)<=3) printf ("YES\n");
                else printf ("NO\n");
            }
        }
        
    }
    return 0;
}
