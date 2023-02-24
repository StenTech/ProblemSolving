
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
    solution of Missing Gnomes problem from open.kattis.com
    https://open.kattis.com/problems/missinggnomes
    
*/

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    set<int> missing;
    vector<int> remaining(m);

    for(int i = 1; i <= n; i++) {
        missing.insert(i);
    }

    for(auto& i : remaining) {
        cin >> i;
        missing.erase(i);
    }

    int k = 0;
    while (k <m) {
        while (!missing.empty() && *missing.begin() < remaining[k]) {
            cout << *missing.begin() << endl;
            missing.erase(missing.begin());
        }
        cout << remaining[k] << endl;
        k++;
    }

    while (!missing.empty()) {
        cout << *missing.begin() << endl;
        missing.erase(missing.begin());
    }
    return 0;
}