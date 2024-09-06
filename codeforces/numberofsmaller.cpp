#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    vector<int> a, b;
    for (int i=1; i<=n; i++) {
        int x;
        scanf ("%d", &x);
        a.push_back(x);
    }
    for (int i=1; i<=m; i++) {
        int x;
        scanf ("%d", &x);
        b.push_back(x);
    }
    int l=0, r=0;
    while (l<(int)a.size() || r<(int)b.size()) {
        if (l==(int)a.size()) {
            printf ("%d ", l);
            r++;
        }
        else if (r==(int)b.size()) break;
        else if (a[l]<b[r]) l++;
        else if (a[l]>=b[r]) {
            printf ("%d ", l);
            r++;
        }
    }
    printf ("\n");
    return 0;
}