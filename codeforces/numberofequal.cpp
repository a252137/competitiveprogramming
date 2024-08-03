#include <bits/stdc++.h>

using namespace std;

int arr[100010], arr2[100010];
vector<int> a, b;
long long int freq1[100010], freq2[100010];
long long int ans;

int main () {

    int n, m;
    scanf ("%d%d", &n, &m);

    for (int i=0; i<n; i++) {

        scanf ("%d", &arr[i]);
        a.push_back(arr[i]);

    }

    for (int i=0; i<m; i++) {

        scanf ("%d", &arr2[i]);
        b.push_back(arr2[i]);

    }

    for (int i=0; i<n; i++) {

        arr[i]=lower_bound(a.begin(), a.end(), arr[i])-a.begin();

    }

    for (int i=0; i<m; i++) {

        int aux = arr2[i];
        arr2[i]=lower_bound(a.begin(), a.end(), arr2[i])-a.begin();
        if (a[arr2[i]] != aux){

                arr2[i]=-1;

        }

    }

    for (int i=0; i<n; i++) freq1[arr[i]]++;

    for (int i=0; i<m; i++) if (arr2[i] != -1) freq2[arr2[i]]++;

    for (int i=0; i<max(n, m); i++) {

        ans += freq1[i]*freq2[i];

    }

    printf ("%lld\n", ans);

}

