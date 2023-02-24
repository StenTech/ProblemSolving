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

int MAX = 0;

int clique(int at, bitset<50> included, const vector<bitset<50>>& neighbours) {
    
    if (at < 0) return included.count();
    
    MAX = max( MAX, clique(at - 1, included, neighbours));

    if ((included & neighbours[at]) == included) {
        included.set(at);
        MAX = max( MAX, clique(at - 1, included, neighbours));
    }
    
    return MAX;
}

/*
    problem:    Maximum Clique
    link:       https://open.kattis.com/problems/maxclique
*/
int main(int argc, char const *argv[]) {

    int v, e;
    cin >> v >> e;

    vector<bitset<50>> neighbours(v);

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        neighbours[a].set(b);
        neighbours[b].set(a);
    }


    // use bitmasks to loop through all possible subsets
    // and use bitmasks for neighborhood checking (faster than adjacency matrix)
    
    cout << clique(v - 1, bitset<50>(), neighbours) << endl;

    return 0;
}