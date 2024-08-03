#include <bits/stdc++.h>

using namespace std;

int vet[100010], vet2[100010], n, i;
vector<int> ans;

int main() {
    scanf ("%d", &n);
    for(i=1; i<=n; i++){
        scanf ("%d", &vet[i]);
        vet2[i]=vet[i];
    }
    sort (vet+1, vet+n+1);
    for(i=1; i<=n; i++){
        if (vet2[i]!=vet[i]){
            ans.push_back(vet2[i]);
        }
    }
    int tamanho=(int)(ans.size());
    printf ("%d\n", tamanho);
    sort (ans.begin(), ans.end());
    for (i=0; i<tamanho; i++){
        printf ("%d ", ans[i]);
    }
    printf ("\n");
    return 0;
}








