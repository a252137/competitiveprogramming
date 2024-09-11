#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

int vet[MAXN], freq[MAXN];
vector<int> p[MAXN];
int num;
long long int atual;

void add_pacote (int r) {
    for (int i=1; i<(int)p[r].size(); i++) {
        freq[p[r][i]]++;
        if (freq[p[r][i]]==1) num++;
    }
    atual += p[r][0];
    return;
}

void remove_pacote (int l) {
    for (int i=1; i<(int)p[l].size(); i++) {
        freq[p[l][i]]--;
        if (freq[p[l][i]]==0) num--;
    }
    atual -= p[l][0];
    return;
}

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=n; i++) {
        int k, v;
        scanf ("%d%d", &k, &v);
        p[i].push_back(v);
        for (int j=1; j<=k; j++) {
            int x;
            scanf ("%d", &x);
            p[i].push_back(x);
        }
    }
    int l=1;
    long long int ans = pow(10, 18);
    int ans_l, ans_r;
    for (int r=1; r<=n; r++) {
        add_pacote(r);
        while (num == m) {
            if (atual<ans) {
                ans = atual;
                ans_l = l;
                ans_r = r;
            }
            remove_pacote(l);
            l++;
        }
    }
    if (ans == pow(10, 18)) printf ("-1\n");
    else {
        printf ("%lld\n", ans);
        printf ("%d %d\n", ans_l, ans_r);
    }
    return 0;
}