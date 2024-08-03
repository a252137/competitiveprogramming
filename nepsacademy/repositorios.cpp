#include <bits/stdc++.h>

using namespace std;

map<int, pair<int, int>> vet;

int main() {
    
    int n, m;
    scanf ("%d%d", &n, &m);
    
    for (int i=1; i<=n; i++) {
        
        int x, y;
        scanf ("%d%d", &x, &y);
        
        vet[x]=make_pair(y, 0);
        
    }
    
    for (int i=1; i<=m; i++) {
        
        int x, y;
        scanf ("%d%d", &x, &y);
        
        if (vet[x].first<y) {
            
            vet[x]=make_pair(y, 1);
            
        }
        
    }
    
    for (map<int, pair<int, int>>::iterator it = vet.begin(); it!=vet.end(); it++) {
        
        if ((*it).second.second==1) printf ("%d %d\n", (*it).first, (*it).second.first);
        
    }
    
    return 0;
    
}


