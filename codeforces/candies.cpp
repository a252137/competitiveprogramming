#include <bits/stdc++.h>

using namespace std;

int vet[200010];

int main() {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n;
        scanf ("%d", &n);
        if (n%2 == 0) {
            printf ("-1\n");
            continue;
        }
        stack<int> ans;
        long long int cur = n;
        for (int i=1; i<=40; i++) {
            long long int aux1 = (cur+1)/2;
            long long int aux2 = (cur-1)/2;
            if (aux1%2==1) {
                ans.push(1);
                cur = aux1;
            }
            else if (aux2%2==1) {
                ans.push(2);
                cur = aux2;
            }
            if (cur == 1) break;
        }
        if (cur == 1) {
            printf ("%d\n", (int)ans.size());
            while (!ans.empty()) {
                printf ("%d ", ans.top());
                ans.pop();
            }
            printf ("\n");
        }
        else {
            printf ("-1\n");
            while (!ans.empty()) ans.pop();
        }
    }
    return 0;
}
