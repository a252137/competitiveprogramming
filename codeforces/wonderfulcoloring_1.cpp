#include <bits/stdc++.h>

using namespace std;

int vet[100];
bool check[100];

int main() {
    
    int t;
    cin>>t;
    
    while (t--) {
        
        string s;
        cin>>s;
        
        for (int i=0; i<(int)s.size(); i++) vet[i]=-1;
        for (int i=0; i<(int)s.size(); i++) check[i]=false;
        
        //0 eh verde, 1 eh vermelho
        
        for (int i=0; i<(int)s.size(); i++) {
            
            if (check[i]==false) {
                
                vet[i]=0;
                check[i]=true;
                int cont = 0;
                
                for (int j=i+1; j<(int)s.size(); j++) {
                    
                    if (s[j]==s[i]){
                        
                        check[j]=true;
                    
                    if (cont == 0) {
                        
                        cont = 1;
                        vet[j]=1;
                        
                    }
                    
                    }
                    
                }
                
            }
            
        }
        
        int ans = 0;
        
        for (int i=0; i<(int)s.size(); i++) {
            
            if (vet[i]==0 || vet[i]==1) ans++;
            
        }
        
        printf ("%d\n", ans/2);
        
    }
    
    return 0;
    
}
