#include <iostream>
using namespace std;

int vet[100010];
int baixo[100010];
int soma[100010];

int main(){

    int n, t;
	scanf ("%d%d", &n, &t);
	
	for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
	
	for (int i=1; i<=n; i++) scanf ("%d", &baixo[i]);
	
	for (int i=1; i<=t; i++) {
		
		int a, b;
		scanf ("%d%d", &a, &b);
		
		soma[a]++;
		soma[b+1]--;
		
	}
	
	for (int i=1; i<=n; i++) soma[i]+=soma[i-1];
	
	for (int i=1; i<=n; i++) {
		
		if (soma[i]%2==0) printf ("%d ", vet[i]);
		
		else printf ("%d ", baixo[i]);
		
	}
	
	printf ("\n");

    return 0;
}



