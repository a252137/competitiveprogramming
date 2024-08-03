#include <bits/stdc++.h>

using namespace std;

char vet[60], ans[60];
int n, cont;

int main() {
    scanf ("%d", &n);
    scanf ("%s", vet);
    int tamanho=strlen(vet);
    for (int i=0; i<tamanho; i++){
        if (vet[i]=='a'){
            ans[cont]='a';
            cont++;
        }
        if (vet[i]=='e'){
            ans[cont]='e';
            cont++;
        }
        if (vet[i]=='i'){
            ans[cont]='i';
            cont++;
        }
        if (vet[i]=='o'){
            ans[cont]='o';
            cont++;
        }
        if (vet[i]=='u'){
            ans[cont]='u';
            cont++;
        }
        
    }
    int size=strlen(ans);
    for (int i=0; i<size/2; i++){
        
        if (ans[i]!=ans[size-i-1]){
            printf ("N\n");
            return 0;
        }
    }
    printf ("S\n");
    return 0;
}












