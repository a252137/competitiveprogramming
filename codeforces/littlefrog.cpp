#include <bits/stdc++.h>

using namespace std;

int n;

int main(){

    scanf ("%d", &n);

    int atual=1;
    int soma=n-1;

    printf ("1 ");

    for (int i=1;soma>0;i++) {

        if (i%2!=0){

            atual=atual+soma;
            soma--;

        }

        else {

            atual=atual-soma;
            soma--;

        }

        printf ("%d ", atual);

    }

    printf ("\n");

}

