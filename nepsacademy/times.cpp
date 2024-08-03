#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, t, h;
    
    vector < pair < int, string > > aluno;
    vector < string > times [1010];
    
    scanf ("%d%d", &n, &t);
    
    for (int i=1; i<=n; i++) {
        
        int x;
        
        string s;
        
        cin >> s >> x;
        
        aluno.push_back(make_pair(x, s));
        
    }
    
    sort (aluno.begin(), aluno.end());
    
    int cont=1;
    
    for (int i=n-1; i>=0; i--) {
        
        times[cont].push_back(aluno[i].second);
        
        if (cont==t) {
            
            cont=1;
            
        }
        
        else {
            
            cont++;
            
        }
        
    }
    
    for (int i=1; i<=t; i++) {
        
        sort (times[i].begin(), times[i].end());
        
        printf ("Time %d\n", i);
        
        for (int j=0; j<(int)(times[i].size()); j++) {
            
            cout << times[i][j] << endl;
            
        }
        
        printf ("\n");
        
    }
    
    return 0;
    
}






