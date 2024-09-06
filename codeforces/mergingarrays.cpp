#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    int a[MAXN], b[MAXN];
    vector<int> c;
    for (int i=1; i<=n; i++) scanf ("%d", &a[i]);
    for (int i=1; i<=m; i++) scanf ("%d", &b[i]);
    int l=1, r=1;
    while (l<=n || r<=m) {
        if (l>n) c.push_back(b[r++]);
        else if (r>m) c.push_back(a[l++]);
        else if (a[l]>b[r]) c.push_back(b[r++]);
        else if (a[l]<=b[r]) c.push_back(a[l++]);
    }
    for (int i=0; i<(int)c.size(); i++) printf ("%d ", c[i]);
    printf ("\n");
    return 0;
}