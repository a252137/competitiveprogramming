#include <bits/stdc++.h>

using namespace std;

int main () {
    
    int t;
    scanf ("%d", &t);
    
    while (t--) {
        
        char vet[400010];
        int a, b;
        scanf ("%d%d", &a, &b);
        
        int n=a+b;
        
        for (int i=1; i<=n; i++) {
            
            scanf (" %c", &vet[i]);
            if (vet[i]=='0') a--;
            else if (vet[i]=='1') b--;
            
        }
        
        bool x=true;
        
        if (a==0 && b==0) {
            
            for (int i=1; i<=n/2; i++) {
                
                if (vet[i]!=vet[n-i+1]) {
                    
                    x=false;
                    break;
                    
                }
                
            }
            
        }
        
        for (int i=1; i<=n/2; i++) {
    
            if (vet[i]=='0' && vet[n-i+1]=='?') {
                
                vet[n-i+1]='0';
                a--;
                
            }
            
            if (vet[i]=='1' && vet[n-i+1]=='?') {
                
                vet[n-i+1]='1';
                b--;
                
            }
            
            if (vet[i]=='?' && vet[n-i+1]=='1') {
                
                vet[i]='1';
                b--;
                
            }
            
            if (vet[i]=='?' && vet[n-i+1]=='0') {
                
                vet[i]='0';
                a--;
                
            }
            
        }
        
        for (int i=1; i<=n; i++) {
            
            if (i==(n/2)+1 && n%2==1) continue;
            
            if (vet[i]=='?' && a>b) {
                
                vet[i]='0';
                vet[n-i+1]='0';
                a=a-2;
                
            }
            
            else if (vet[i]=='?' && b>=a) {
                
                vet[i]='1';
                vet[n-i+1]='1';
                b=b-2;
                
            }
            
        }
        
        if (n%2==1 && (a!=0 || b!=0)) {
            
            if (a>b) {
                
                vet[(n/2)+1]='0';
                a--;
                
            }
            
            else {
                
                vet[(n/2)+1]='1';
                b--;
                
            }
            
        }
        
        for (int i=1; i<=n/2; i++) {
                
            if (vet[i]!=vet[n-i+1]) {
                    
                x=false;
                break;
                    
            }
                
        }
        
        if (b==0 && a==0 && x==true) {
            
            for (int i=1; i<=n; i++) printf ("%c", vet[i]);
            printf ("\n");
            
        }
        
        else printf ("-1\n");
        
    }
    
    
}
