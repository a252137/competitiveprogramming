#include <bits/stdc++.h>

using namespace std;

int main () {
    
    int t;
    scanf ("%d", &t);
    
    while (t--) {
        
        deque<int> vet;
        int n;
        scanf ("%d", &n);
        
        for (int i=1; i<=n; i++) {
            
            int x;
            scanf ("%d", &x);
            
            if (x%2==0) vet.push_back(x);
            else vet.push_front(x);
            
        }
        
        for (int i=0; i<(int)vet.size(); i++) printf ("%d ", vet[i]);
        printf ("\n");
        vet.clear();
        
    }
    
}
