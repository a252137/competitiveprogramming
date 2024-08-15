#include <bits/stdc++.h>
#define MAXN 50010

using namespace std;

int pai[MAXN], tam[MAXN];

int find (int x) {
    if (x==pai[x]) return x;
    return pai[x] = find(pai[x]);
}

void join (int u, int v) {
    int a = find(u), b = find(v);
    if (a==b) return;
    if (tam[a]>tam[b]) {
        pai[b]=a;
        tam[a]+=tam[b];
    }
    else {
        pai[a]=b;
        tam[b]+=tam[a];
    }
    return;
}

int main () {
    int n, m, k;
    scanf ("%d%d%d", &n, &m, &k);
    for (int i=1; i<=n; i++) {
        pai[i]=i;
        tam[i]=1;
    }
    vector<char> ans;
    vector<pair<char, pair<int, int>>> aux;
    while (m--) {
        int a, b;
        scanf ("%d%d", &a, &b);
    }
    while (k--) {
        char s[10];
        int u, v;
        scanf ("%s", s);
        scanf ("%d%d", &u, &v);
        aux.push_back({s[0], {u, v}});
    }
    for (int i=(int)aux.size()-1; i>=0; i--) {
        char id = aux[i].first;
        int u = aux[i].second.first;
        int v = aux[i].second.second;
        if (id == 'a') {
            if (find(u)==find(v)) ans.push_back('y');
            else ans.push_back('n');
        }
        else if (id == 'c') {
            join(u, v);
        }
    }
    for (int i=(int)ans.size()-1; i>=0; i--) {
        if (ans[i]=='y') printf ("YES\n");
        else if (ans[i]=='n') printf ("NO\n");
    }
    return 0;
}