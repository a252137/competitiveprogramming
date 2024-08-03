#include <bits/stdc++.h>

using namespace std;

int arr[400010];
vector<int> a;
long long int freq[400010];
long long int ans;


int main () {

    int n, k;
    scanf ("%d%d", &n, &k);

    for (int i=0; i<n; i++) {

        scanf ("%d", &arr[i]);
        a.push_back(arr[i]);

    }
    
    sort (a.begin(), a.end());

    for (int i=0; i<n; i++) {

        arr[i]=lower_bound(a.begin(), a.end(), arr[i])-a.begin();

    }
    
    int l=0, r=0;
    freq[arr[r]] = 1;
    
    while (l<=r && r<n) {
        
        if (freq[arr[r]]>=k) {
            
            ans += n-r;
            freq[arr[l]]--;
            l++;
            
        }
        
        if (freq[arr[r]]<k) {
            
            r++;
            freq[arr[r]]++;
            
        }
        
        
    }

    printf ("%lld\n", ans);

}

