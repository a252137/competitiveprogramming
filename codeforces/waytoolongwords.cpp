#include <bits/stdc++.h>

using namespace std;

int n, i;

int main() {
    
    scanf ("%d", &n);
    for (i=1; i<=n; i++) {
        string word;
        cin >> word;
        int tamanho=(int)(word.size());
        if (tamanho<=10) {
            for (int j=0; j<tamanho; j++){
                printf ("%c", word[j]);
            }
            printf ("\n");
        }
        else {
            printf ("%c", word[0]);
            printf ("%d", tamanho-2);
            printf ("%c\n", word[tamanho-1]);
        }
    }
    
    return 0;
}













