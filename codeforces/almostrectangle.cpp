#include <bits/stdc++.h>

using namespace std;

int main () {
    
    int t;
    scanf ("%d", &t);
    
    while (t--) {
        
        int n;
        scanf ("%d", &n);
        char matriz[410][410];
        vector<pair<int, int>> ans;
        
        for (int i=1; i<=n; i++) {
            
            for (int j=1; j<=n; j++) {
                
                scanf (" %c", &matriz[i][j]);
                
                if (matriz[i][j]=='*') ans.push_back(make_pair(i, j));
                
            }
            
        }
        
        matriz[ans[0].first][ans[1].second] = '*';
        matriz[ans[1].first][ans[0].second] = '*';
        
        if (ans[1].second==ans[0].second) {
            
            bool a=false, b=false;
            
            for (int i=1; i<=n; i++) {
                
                for (int j=1; j<=n; j++) {
                    
                    if (j!=ans[0].second && i==ans[0].first && a==false) {
                        
                        matriz[i][j]='*';
                        a=true;
                        
                    }
                    
                    if (j!=ans[1].second && i==ans[1].first && b==false) {
                        
                        matriz[i][j]='*';
                        b=true;
                        
                    }
                    
                }

                
            }
            
            
        }
        
        else if (ans[1].first==ans[0].first) {
            
            bool a=false, b=false;
            
            for (int i=1; i<=n; i++) {
                
                for (int j=1; j<=n; j++) {
                    
                    if (i!=ans[0].first && j==ans[0].second && a==false) {
                        
                        matriz[i][j]='*';
                        a=true;
                        
                    }
                    
                    if (i!=ans[1].first && j==ans[1].second && b==false) {
                        
                        matriz[i][j]='*';
                        b=true;
                        
                    }
                    
                    
                }
                

                
            }
            

            
        }
        
        ans.clear();
        
        for (int i=1; i<=n; i++) {
            
            for (int j=1; j<=n; j++) {
                
                printf ("%c", matriz[i][j]);
                
            }
            
            printf ("\n");
            
        }
        
    }
    
}
