#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MAXN 200010
#define lli pair<long long int, int>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 

int main () {
    ordered_set vet;
    int n, k;
    int v[MAXN];
    cin>>n>>k;
    for (int i=1; i<=n; i++) {
        cin>>v[i];
    }
    for (int i=1; i<=k; i++) vet.insert({v[i], i});
    int mid;
    if (k%2==0) mid = (k/2)-1;
    else mid = k/2;
    cout<<((*vet.find_by_order(mid))).first<<" ";
    for (int i=k+1; i<=n; i++) {
        vet.erase({v[i-k], i-k});
        vet.insert({v[i], i});
        cout<<((*vet.find_by_order(mid))).first<<" ";
    }
    cout<<endl;
    return 0;
}