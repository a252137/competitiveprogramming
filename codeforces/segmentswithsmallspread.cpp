#include <bits/stdc++.h>
#define MAXN 100010
#define lli long long int

using namespace std;

stack<long long int> s1, s2, max1, max2, min1, min2;

void inserir (lli x) {
    s2.push(x);
    if (!max2.empty()) max2.push(max(max2.top(), x));
    else max2.push(x);
    if (!min2.empty()) min2.push(min(min2.top(), x));
    else min2.push(x);
    return;
}

lli calc_max () {
    if (s1.empty()==true) return max2.top();
    if (s2.empty()==true) return max1.top();
    else return max(max2.top(), max1.top()); 
}

lli calc_min () {
    if (s1.empty()==true) return min2.top();
    if (s2.empty()==true) return min1.top();
    else return min(min2.top(), min1.top()); 
}

void retirar () {
    if (s1.empty()==true) {
        s1.push(s2.top());
        min1.push(s2.top());
        max1.push(s2.top());
        s2.pop();
        min2.pop();
        max2.pop();
        while (!s2.empty()) {
            s1.push(s2.top());
            min1.push(min(min1.top(), s2.top()));
            max1.push(max(max1.top(), s2.top()));
            s2.pop();
            min2.pop();
            max2.pop();
        }
    }
    s1.pop();
    max1.pop();
    min1.pop();
}

int main () {
    int n;
    lli k, v[MAXN];
    scanf ("%d%lld", &n, &k);
    for (int i=1; i<=n; i++) scanf ("%lld", &v[i]);
    lli ans = 0;
    int l=1;
    for (int r=1; r<=n; r++) {
        inserir(v[r]);
        lli maxi = calc_max(), mini = calc_min();
        while (maxi-mini>k) {
            retirar();
            maxi = calc_max(), mini = calc_min();
            l++;
        }
        ans += r-l+1;
    }
    printf ("%lld\n", ans);
    return 0;
}