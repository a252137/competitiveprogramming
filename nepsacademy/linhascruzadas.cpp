#include <bits/stdc++.h>

using namespace std;
int i, inv;
void merges (vector<int>&v){
    if (v.size()==1){
        return;
    }
    int t=v.size(), mid=t/2;
    vector<int>vd;
    vector<int>ve;
    for (i=0; i<mid; i++){
        ve.push_back(v[i]);
    }
    for (i=mid; i<t; i++){
        vd.push_back(v[i]);
    }
    merges(vd), merges(ve);
    int tame=ve.size(), tamd=vd.size(), pointe=0, pointd=0;
    for (i=0; i<t; i++){
        if (pointe>=tame){
            v[i]=vd[pointd];
            pointd++;
        }
        else if (pointd>=tamd){
            v[i]=ve[pointe];
            pointe++;
        }
        else {
            if (vd[pointd]>=ve[pointe]){
                v[i]=ve[pointe];
                pointe++;
            }
            else {
                v[i]=vd[pointd];
                pointd++;
                inv=inv+(tame-pointe);
            }
        }
    }
    
    
}

int main() {
    int a, n;
    vector<int>my;
    scanf ("%d", &n);
    for (i=0; i<n; i++){
        scanf ("%d", &a);
        my.push_back(a);
    }
    merges(my);
    printf ("%d\n", inv);
    return 0;
}
