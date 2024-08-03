#include <bits/stdc++.h>

using namespace std;

string title(string F){
	for (int i=0; i<(int)(F.size()); i++){
	    F[i]=tolower(F[i]);
	}
	F[0]=toupper(F[0]);
	for (int i=1; i<(int)(F.size()); i++){
	    if (F[i-1]==' '){
	        F[i]=toupper(F[i]);
	    }
	}
	return F;
}

int main(){ 
	string F;

	getline(cin, F);

	cout << title(F) << "\n";
}
