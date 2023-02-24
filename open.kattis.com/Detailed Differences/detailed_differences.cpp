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

    cin >> n;

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        cout << a << endl << b << endl;

        for (int j = 0; j < a.size(); j++) {
            if (a[j] == b[j]) cout << ".";
            else cout << "*";
        }

        cout << endl << endl;
    }

    return 0;
}