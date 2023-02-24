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

    int r, c, zr, zc;

    cin >> r >> c >> zr >> zc;

    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < zr; j++) {
            for (int k = 0; k < s.size(); k++) {
                for (int l = 0; l < zc; l++) {
                    cout << s[k];
                }
            }
            cout << endl;
        }
    }
    

    return 0;
}