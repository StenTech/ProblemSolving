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


/*
    problem:    Maximum Clique
    link:       https://open.kattis.com/problems/maxclique
*/
int main(int argc, char const *argv[]) {

    int v, e;
    cin >> v >> e;

    map<int, int> neighborhood = map<int, int>();

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        neighborhood[a] |= (1 << b);
        neighborhood[b] |= (1 << a);
    }

    // loop edges are allowed
    for (int i = 0; i < v; i++) { 
        neighborhood[i] |= (1 << i);
    }

    int max_clique = 0;

    // use bitmasks to loop through all possible subsets
    // and use bitmasks for neighborhood checking (faster than adjacency matrix)
    
    
    for (int subset = 0; subset < (1 << v); subset++) {
        bool is_clique = true;
        // iterate through all vertices in the subset
        for (int i = 0; i < v; i++) {
            if (subset & (1 << i)) {
                // check if the vertex is connected to all other vertices in the subset
                if ((neighborhood[i] & subset) != subset) {
                    is_clique = false;
                    break;
                }
            }
        }

        if (is_clique) {
            int clique_size = __builtin_popcount(subset);
            max_clique = max(max_clique, clique_size);
        }
    }

    cout << max_clique << endl;

    return 0;
}
