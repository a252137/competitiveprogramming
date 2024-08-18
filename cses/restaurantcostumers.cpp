#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf ("%d", &n);
    int ans = 0, at = 0;
    vector<pair<int, int>> vet;
    for (int i=1; i<=n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        vet.push_back({a, -1});
        vet.push_back({b, 1});
    }
    sort(vet.begin(), vet.end());
    for (int i=0; i<(int)vet.size(); i++) {
        at-=vet[i].second;
        ans = max(ans, at);
    }
    printf ("%d\n", ans);
    return 0;
}