#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n, m;
        scanf ("%d%d", &n, &m);
        char s[100010];
        for (int i=1; i<=n; i++) scanf (" %c", &s[i]);
        int vet[100010];
        for (int i=1; i<=m; i++) scanf ("%d", &vet[i]);
        deque<char> c;
        for (int i=1; i<=m; i++) {
            char aux;
            scanf (" %c", &aux);
            c.push_back(aux);
        }
        sort (vet+1, vet+m+1);
        sort (c.begin(), c.end());
        for (int i=1; i<=m; i++) {
            if (vet[i]==vet[i+1] && i!=m) c.pop_back();
            else {
                s[vet[i]] = c.front();
                c.pop_front();
            }
        }
        for (int i=1; i<=n; i++) printf ("%c", s[i]);
        printf ("\n");
    }
    return 0;
}
