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


int main(int argc, char const *argv[]) {

    int w, p, ps[100];

    cin >> w >> p;

    
    set<int> p_set;

    for (int i = 0; i < p; i++)
    {
        cin >> ps[i];
        for (int j = 0; j < i; j++)
        {
            p_set.insert(ps[i] - ps[j]);
        }

        p_set.insert(ps[i]);
        p_set.insert(abs(w - ps[i]));        
    }

    p_set.insert(w);

    for (auto &&el : p_set)
    {
        cout << el << " ";
    }
    
    return 0;
}