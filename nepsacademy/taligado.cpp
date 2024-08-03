#include <bits/stdc++.h>

using namespace std;

vector<int> vet[100010];

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=m; i++) {
        int t, a, b;
        scanf ("%d%d%d", &t, &a, &b);
        if (t==0) {
            int check = 0;
            for (int i=0; i<(int)vet[a].size(); i++) {
                if (vet[a][i] == b) check = 1;
            }
            printf ("%d\n", check);
        }
        else {
            vet[a].push_back(b);
            vet[b].push_back(a);
        }
    }
    return 0;
}