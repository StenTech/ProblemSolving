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

    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<string> names(n);

        for (int i = 0; i < n; i++) {
            string name;
            cin >> name;
            names[i] = name;
        }

        stable_sort(names.begin(), names.end(), [](string a, string b) {
            return a.substr(0, 2) < b.substr(0, 2);
        });

        for (int i = 0; i < n; i++) {
            cout << names[i] << endl;
        }

        cout << endl;
    }

    return 0;
}