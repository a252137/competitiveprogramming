#include <bits/stdc++.h>
 
using namespace std;
 
int main () {
    int a;
    map<string, int> aux;
    map<int, string> reverso;
    map<string, int> adicionado;
    vector<pair<string, string>> n_s;
    vector<int> grafo[110];
    int teste = 1;
    while (true) {
        cin>>a;
        cin.ignore();
        int cont = 1;
        if (a==0) break;
        while (a--) {
            string s;
            getline(cin, s);
            string at = "";
            vector<string> adj;
            for (int i=0; i<(int)s.size()-1; i++) {
                if (s[i]==',') {
                    if (aux.find(at)==aux.end()) {
                        aux[at] = cont++;
                        reverso[aux[at]] = at;
                    }
                    adj.push_back(at);
                    at="";
                    continue;
                }
                if (s[i]==' ' && s[i-1]==',') continue;
                at+=s[i];
            }
            if (aux.find(at)==aux.end()) {
                aux[at] = cont++;
                reverso[aux[at]] = at;
            }
            adj.push_back(at);
            at = "";
            int cont2 = 0;
            pair<string, string> n_s_atual;
            n_s_atual.first = "";
            n_s_atual.second = "";
            for (int i=0; i<(int)s.size()-1; i++) {
                if ((s[i]>=65 && s[i]<=90) && s[i+1]=='.') {
                    n_s_atual.second += s[i];
                    n_s_atual.second += s[i+1];
                    n_s_atual.second += ' ';
                    continue;
                }
                if (s[i]=='.' || s[i]==' ') continue;
                if (s[i]==',') {
                    n_s_atual.first = at;
                    string n_s_completo = n_s_atual.second;
                    n_s_completo += n_s_atual.first;
                    if (adicionado.find(n_s_completo)==adicionado.end()) {
                        n_s.push_back(n_s_atual);
                        adicionado[n_s_completo] = 1;
                    }
                    n_s_atual.first = "";
                    n_s_atual.second = "";
                    at = "";
                    continue;
                }
                at+=s[i];
            }
            n_s_atual.first = at;
            string n_s_completo = n_s_atual.second;
            n_s_completo += n_s_atual.first;
            if (adicionado.find(n_s_completo) == adicionado.end()) {
                n_s.push_back(n_s_atual);
                adicionado[n_s_completo] = 1;
            }
            for (int i=0; i<(int)adj.size(); i++) {
                for (int j=i+1; j<(int)adj.size(); j++) {
                    grafo[aux[adj[i]]].push_back(aux[adj[j]]);
                    grafo[aux[adj[j]]].push_back(aux[adj[i]]);
                }
            }
            adj.clear();
        }
        queue<int> q;
        q.push(aux["P. Erdos"]);
        int dist[110];
        for (int i=1; i<cont; i++) dist[i] = 1000000000;
        dist[aux["P. Erdos"]] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i=0; i<(int)grafo[u].size(); i++) {
                int v = grafo[u][i];
                if (dist[v]==1000000000) {
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
            }
        }
        cout<<"Teste "<<teste++<<endl;
        // OBS: tirar duplicatas do vector
        sort(n_s.begin(), n_s.end());
        for (int i=0; i<(int)n_s.size(); i++) {
            string n_s_completo = n_s[i].second;
            n_s_completo += n_s[i].first;
            if (n_s_completo.compare("P. Erdos")==0) continue;
            if (dist[aux[n_s_completo]] == 1000000000) cout<<n_s_completo<<": infinito"<<endl;
            else cout<<n_s_completo<<": "<<dist[aux[n_s_completo]]<<endl; 
        }
        cout<<endl;
        aux.clear();
        reverso.clear();
        adicionado.clear();
        n_s.clear();
        for (int i=1; i<cont; i++) grafo[i].clear();
    }
    return 0;
}