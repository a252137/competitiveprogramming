#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    long long int n;
    scanf ("%lld", &n);
    long long int ans = 0;
    for (int i=1; i<=15; i++) ans += n/(pow(5, i));
    printf ("%lld\n", ans);
    return 0;
}
