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

    map<string, bool> m; // m stocke the name of the person and if he is inside or not

    cin >> n;

    for (int i = 0; i < n; i++) {
        string name, action;
        
        cin >> action >> name;
        
        if (action == "entry") {
            if (m[name] == true) {
                cout << name << " entered (ANOMALY)" << endl;
            } else {
                cout << name << " entered" << endl;
                m[name] = true;
            }
        } else {
            if (m[name] == false) {
                cout << name << " exited (ANOMALY)" << endl;
            } else {
                cout << name << " exited" << endl;
                m[name] = false;
            }
        }
    }

    return 0;
}