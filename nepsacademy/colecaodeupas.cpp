#include <bits/stdc++.h>

using namespace std;

int n, m, u, v, x;
int vet[100010];
vector<int> adj [100010];

int main (){
	scanf ("%d%d", &n, &m);
	for (int i=0; i<m; i++){
		scanf ("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=n; i>=1; i--){
		if (vet[i]==0){
		    for (int j=0; j<(int)(adj[i].size()); j++){
			    vet[adj[i][j]]=1;
		    }
	}
	}
	for (int i=1; i<=n; i++){
		if (vet[i]==0) x++;
	}
	printf ("%d\n", x);
	for (int i=1; i<=n; i++){
		if (vet[i]==0){
			printf ("%d ", i);
		}
	}
	printf ("\n");
	return 0;
	
}
