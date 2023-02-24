#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

// definition d'une fonction de comparaison d'un vecteur de taille 3
// on compare les deux derniers éléments du vecteur
bool compare(const vector<int>& a, const vector<int>& b) {
    if (a[1] != b[1]) {
        return a[1] < b[1];
    }

    return a[2] < b[2];

}


int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;

    if (m < n) {
        cout << "impossible" << endl;
        return 0;
    }

    map<int, set<pair<int, int>>> graph;

    for (int i=1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].insert({b, i});
        graph[b].insert({a, i});
    }

    vector<int> path;

    int current = 1;

    while (graph.size() > 0) {
        if (graph[current].size() == 0) {
            cout << "impossible" << endl;
            return 0;
        }

        auto it = graph[current].begin();
        int next = it->first;
        int line = it->second;

        path.push_back(line);

        graph[current].erase(it);
        graph[next].erase({current, line});

        if (graph[current].size() == 0) {
            graph.erase(current);
        }

        if (graph[next].size() == 0) {
            graph.erase(next);
        }

        current = next;
    }

    for (int i=0; i < path.size(); i++) {
        cout << path[i] << endl;
    }
    

    return 0;
}

/*
vector<vector<int>> lines(m, vector<int>(3, 0));
    int a, b, nb_lines = 0;

    for(int i = 0; i < m; i++) {
        
        cin >> a >> b;
        if (b == a+1) {
            lines[i][0] = i + 1;
            lines[i][1] = a;
            lines[i][2] = b;
            nb_lines++;
        }
        else if (a == b+1) {
            lines[i][0] = i + 1;
            lines[i][1] = b;
            lines[i][2] = a;
            nb_lines++;
        }
        else if (a==n && b==1) {
            lines[i][0] = i + 1;
            lines[i][1] = a;
            lines[i][2] = b;
            nb_lines++;
        }
        else if (a==1 && b==n) {
            lines[i][0] = i + 1;
            lines[i][1] = b;
            lines[i][2] = a;
            nb_lines++;
        }
        
    }

    if (nb_lines < n) {
        cout << "impossible" << endl;
        return 0;
    }
    
    sort(lines.begin(), lines.end(), compare);
    
    for(int i = 0; i < m; i++) {
        if (lines[i][0] != 0) {
            cout << lines[i][0] << endl;
            if (lines[i][1] == n && lines[i][2] == 1) {
                return 0;
            }
        }
    }
*/