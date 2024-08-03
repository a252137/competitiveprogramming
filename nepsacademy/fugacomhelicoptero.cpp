#include <stdio.h>

using namespace std;

int h, p, f, d, i;

int main (){
	scanf ("%d%d%d%d", &h, &p, &f, &d);
	for (i=f; 1==1; i=i+d){
		if (i==p){
			printf ("N\n");
			break;
		}
		else if (i==h){
			printf ("S\n");
			break;
		}
		if (i==0 && d==-1){
			i=16;
		}
		else if (i==15 && d==1){
			i=-1;
		}
	}
	return 0;
	
}
