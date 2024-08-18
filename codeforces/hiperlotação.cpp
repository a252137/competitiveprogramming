#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main () {
    int n, k, fun = 0;
    scanf ("%d%d", &n, &k);
    priority_queue<lli, vector<lli>, greater<lli>> q;
    vector<pair<lli, int>> vet;
    for (int i=1; i<=n; i++) {
        lli a, b;
        scanf ("%lld%lld", &a, &b);
        vet.push_back({a, 1});
        if (fun<k) {
            vet.push_back({a+b, -1});
            q.push(a+b);
            fun++;
        }
        else {
            lli fim = q.top();
            q.pop();
            vet.push_back({max(a, fim)+b, -1});
            q.push(max(a, fim)+b);
        }
    }
    sort(vet.begin(), vet.end());
    int ans = 1, at = 0;
    for (int i=0; i<(int)vet.size(); i++) {
        at += vet[i].second;
        ans = max(ans, at);
    }
    printf ("%d\n", ans);
    return 0;
}