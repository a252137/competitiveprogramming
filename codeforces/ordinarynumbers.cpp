#include <bits/stdc++.h>

using namespace std;

vector<int> vet;

int main () {

    int t;
    scanf ("%d", &t);

    for (int i=1; i<=9; i++) vet.push_back(i);

    for (int i=1; i<=9; i++) vet.push_back((i*10)+i);

    for (int i=1; i<=9; i++) vet.push_back((i*100)+(i*10)+i);

    for (int i=1; i<=9; i++) vet.push_back((i*1000)+(i*100) +(i*10)+i);

    for (int i=1; i<=9; i++) vet.push_back((i*10000)+(i*1000) +(i*100)+(i*10)+i);

    for (int i=1; i<=9; i++) vet.push_back((i*100000)+(i*10000) +(i*1000)+(i*100)+(i*10)+i);

    for (int i=1; i<=9; i++) vet.push_back((i*1000000)+(i*100000) +(i*10000)+(i*1000)+(i*100)+(i*10)+i);

    for (int i=1; i<=9; i++) vet.push_back((i*10000000)+(i*1000000) +(i*100000)+(i*10000)+(i*1000)+(i*100)+(i*10)+i);

    for (int i=1; i<=9; i++) vet.push_back((i*100000000)+(i*10000000)+(i*1000000) +(i*100000)+(i*10000)+(i*1000)+(i*100)+(i*10)+i);

    while (t--) {

        int n;
        scanf ("%d", &n);

        //calcular todos os ordináros até 10^9 e armazenar na ordem

        int l = 0, r = (vet.size())-1, mid, ans;

        while (l<=r) {

            mid = (l+r)/2;

            if (vet[mid]<=n) {

                ans = mid;
                l=mid+1;

            }

            else r=mid-1;

        }

        printf ("%d\n", ans+1);

    }

}

