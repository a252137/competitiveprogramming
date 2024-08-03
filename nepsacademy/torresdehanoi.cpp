#include <bits/stdc++.h>

using namespace std;

long long int ans;

int main() {
    int n;
    for(int i=1; true; i++){
        scanf ("%d", &n);
        if (n==0) return 0;
        ans=pow(2,n)-1;
        printf ("Teste %d\n%lld\n\n", i, ans);
        ans=0;
    }
    return 0;
}








