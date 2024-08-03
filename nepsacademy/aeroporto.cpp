#include <bits/stdc++.h>

using namespace std;

int a, v, x, y, maior;
int aero[110];
int i;

int main() {
    for (i=1; 1==1; i++){
        scanf ("%d%d", &a, &v);
        if (a==0 && v==0){
            return 0;
        }
        for (int j=1; j<=v; j++){
            scanf ("%d%d", &x, &y);
            aero[x]++;
            aero[y]++;
        }
        for (int j=1; j<=a; j++){
            maior=max(maior, aero[j]);
        }
        printf ("Teste %d\n", i);
        for (int j=1; j<=a; j++){
            if (aero[j]==maior){
                printf ("%d ", j);
            }
        }
        printf ("\n\n");
        for (int j=1; j<=a; j++) aero[j]=0;
        maior=0;
    }
    return 0;
}







